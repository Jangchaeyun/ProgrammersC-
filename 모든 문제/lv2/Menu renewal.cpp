#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;

void dfs(int idx, string tmp, string order) {
	if (tmp.size() > order.size()) {
		return;
	}
	m[tmp]++;
	for (int i = idx; i < order.size(); i++) {
		dfs(i + 1, tmp + order[i], order);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (auto order : orders) {
		sort(order.begin(), order.end());
		dfs(0, "", order);
	}

	for (auto setSize : course) {
		int mostOrdered = 0;
		for (auto menu : m) {
			if (menu.first.size() == setSize)
				mostOrdered = max(mostOrdered, menu.second);
		}
		if (mostOrdered <= 1) continue;
		for (auto menu : m) {
			if (menu.first.size() == setSize && menu.second == mostOrdered)
				answer.push_back(menu.first);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}