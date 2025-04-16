#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
	vector<int> answer;
	if (n > s)
	{
		answer.push_back(-1);
		return answer;
	}

	int Basic = s / n;
	int Extra = s % n;
	answer.assign(n, Basic);
	for (int i = answer.size() - 1; i >= 0 && Extra > 0; i--)
	{
		answer[i]++;
		Extra--;
	}

	return answer;
}