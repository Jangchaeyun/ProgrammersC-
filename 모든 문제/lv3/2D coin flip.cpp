#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define INF 987654321

int diff[11][11];
int N, M;
int answer = INF;
vector<int> vec;

int solve() {
	int ret = 0;
	int temp[11][11];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			temp[i][j] = diff[i][j];
	}

	for (auto i : vec) {
		for (int j = 0; j < M; j++) {
			temp[i][j] ^= 1;
		}
		ret++;
	}

	for (int j = 0; j < M; j++) {
		if (temp[0][j] == 1) ret++;
		for (int i = 0; i < N; i++) {
			if (temp[i][j] != temp[0][j]) {
				return INF;
			}
		}
	}

	return ret;
}

void choose(int idx) {
	if (idx == N) {
		answer = min(answer, solve());
		return;
	}
	vec.push_back(idx);
	choose(idx + 1);
	vec.pop_back();
	choose(idx + 1);
}

int solution(vector<vector<int>> beg, vector<vector<int>> tar) {
	N = beg.size();
	M = beg[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (beg[i][j] != tar[i][j])
				diff[i][j] = 1;
			else diff[i][j] = 0;
		}
	}
	choose(0);
	if (answer == INF) return -1;
	else return answer;
}