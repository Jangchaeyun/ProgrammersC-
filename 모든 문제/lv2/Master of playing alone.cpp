#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
	int n = cards.size();
	vector<bool> vis(n + 1, false);
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		int cur = cards[i], cnt = 0;
		while (!vis[cur])
		{
			vis[cur] = true;
			cur = cards[cur - 1];
			cnt++;
		}
		if (cnt) res.push_back(cnt);
	}
	sort(res.begin(), res.end(), greater<int>());
	if (res.size() > 1) return res[0] * res[1];
	return 0;
}