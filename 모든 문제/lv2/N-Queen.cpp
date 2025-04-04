#include <string>
#include <vector>

using namespace std;

int answer;

bool isAble(int idx, int cnt, vector<int>& board) {
	for (int i = 0; i < cnt; i++) {
		if (board[i] == idx) return false;
		if (abs(board[i] - idx) == abs(cnt - i)) return false;
	}
	return true;
}

void dfs(int cnt, int n, vector<int>& board) {
	if (cnt == n) {
		answer++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isAble(i, cnt, board)) {
			board[cnt] = i;
			dfs(cnt + 1, n, board);
		}
	}
}

int solution(int n) {
	vector<int> board(n, 0);
	dfs(0, n, board);
	return answer;
}