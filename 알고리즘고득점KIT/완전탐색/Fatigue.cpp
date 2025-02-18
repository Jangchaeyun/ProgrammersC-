#include <string>
#include <vector>
#define MAX 8

using namespace std;

int answer = 0;
bool visited[MAX] = { 0 };

void dfs(int cnt, int k, vector<vector<int>>& dungeous) {
	if (cnt > answer) answer = cnt;

	for (int i = 0; i < dungeous.size(); i++) {
		if (!visited[i] && dungeous[i][0] <= k) {
			visited[i] = true;
			dfs(cnt + 1, k - dungeous[i][1], dungeous);
			visited[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeous) {
	dfs(0, k, dungeous);

	return answer;
}