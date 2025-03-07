#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0, size = board.size();
	stack<int> st;
	for (auto move : moves) {
		int target = 0; move--;
		for (int i = 0; i < size; i++) {
			if (board[i][move]) {
				target = board[i][move];
				board[i][move] = 0;
				break;
			}
		}
		if (!st.empty() && st.top() == target) {
			st.pop();
			answer += 2;
		}
		else if (target) st.push(target);
	}
	return answer;
}