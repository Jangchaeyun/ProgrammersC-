#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void fillEmpty(int m, int n, vector<string>& board) {
    for (int j = 0; j < n; j++) {
        string tmp = "";
        for (int i = m - 1; i >= 0; i--) if (board[i][j] != ' ') tmp += board[i][j];
        int i = m - 1;
        for (auto c : tmp) board[i--][j] = c;
        for (; i >= 0; i--) board[i][j] = ' ';
    }
}

bool is_hit(int i, int j, vector<string>& board, vector<vector<bool>>& vis) {
    if (board[i][j] != board[i + 1][j] ||
        board[i][j] != board[i][j + 1] ||
        board[i][j] != board[i + 1][j + 1]) return false;
    vis[i][j] = true;
    vis[i + 1][j] = true;
    vis[i][j + 1] = true;
    vis[i + 1][j + 1] = true;
    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    while (1) {
        bool done = true;
        fill(vis.begin(), vis.end(), vector<bool>(n, false));
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] != ' ' && is_hit(i, j, board, vis)) done = false;
            }
        }
        if (done) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) board[i][j] = ' ';
            }
        }
        fillEmpty(m, n, board);
    }
    for (auto s : board) {
        for (auto c : s) if (c == ' ') answer++;
    }
    return answer;
}