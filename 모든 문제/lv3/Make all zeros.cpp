#include <string>
#include <vector>
#define MAX 300000

using namespace std;

long long answer = 0;
long long weight[MAX];
vector<vector<int>> info(MAX);

void dfs(int node, int parent) {
	for (int i = 0; i < info[node].size(); i++) {
		if (info[node][i] != parent) {
			dfs(info[node][i], node);
		}
	}

	weight[parent] += weight[node];
	answer += abs(weight[node]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
	for (int i = 0; i < a.size(); i++)
		weight[i] = a[i];

	for (auto edge : edges) {
		info[edge[0]].push_back(edge[1]);
		info[edge[1]].push_back(edge[0]);
	}

	dfs(0, 0);

	if (weight[0] != 0) answer = -1;
	return answer;
}