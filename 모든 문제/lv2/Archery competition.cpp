#include <string>
#include <vector>
using namespace std;

int res_max = 0;
vector<int> answer = { -1 };

void dfs(int cnt, int n, int idx, vector<int> info, vector<int> tmp) {
	if (cnt == n)
	{
		int res = 0;
		for (int i = 0; i < 11; i++)
		{
			if (tmp[i] > info[i]) res += (10 - i);
			else if (info[i]) res -= (10 - i);
		}
		if (res > res_max && res)
		{
			res_max = res;
			answer = tmp;
		}
		else if (res == res_max && res)
		{
			for (int i = 10; i >= 0; i--)
			{
				if (answer[i] > tmp[i]) return;
				else if (answer[i] < tmp[i])
				{
					answer = tmp;
					break;
				}
			}
		}
		return;
	}
	for (int i = idx; i <= 10; i++)
	{
		int num = info[i] + 1;
		if (num > n - cnt) num = n - cnt;
		tmp[i] = num;
		dfs(cnt + num, n, i + 1, info, tmp);
		tmp[i] = 0;
	}
}

vector<int> solution(int n, vector<int> info)
{
	vector<int> tmp(11, 0);
	dfs(0, n, 0, info, tmp);
	return answer;
}