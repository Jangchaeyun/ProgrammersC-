#include <string>
#include <vector>

using namespace std;

int d_x[4] = { 1, -1, 0, 0 };
int d_y[4] = { 0, 0, 1, -1 };
int minCost = 9999999;
int b_size;
int grp[25][25][4];

void dfs(vector<vector<int>>& board, int x, int y, int cost, int dir) {
    if (minCost < cost) {
        return;
    }

    if (x == b_size - 1 && y == b_size - 1) {
        minCost = min(cost, minCost);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + d_x[i];
        int next_y = y + d_y[i];

        if (next_x >= 0 && next_x < b_size && next_y >= 0 && next_y < b_size && board[next_x][next_y] != 1) {
            int nextCost = cost + 100;

            // 방향이 달라짐
            if (dir == 0 || dir == 1) {
                if (i == 2 || i == 3) {
                    nextCost += 500;
                }
            }

            if (dir == 2 || dir == 3) {
                if (i == 0 || i == 1) {
                    nextCost += 500;
                }
            }

            if (grp[next_x][next_y][i] > nextCost) {
                grp[next_x][next_y][i] = nextCost;
                dfs(board, next_x, next_y, nextCost, i);
            }
        }
    }

}

int solution(vector<vector<int>> board) {
    int answer = 0;
    b_size = board.size();


    for (int i = 0; i < b_size; i++) {
        for (int j = 0; j < b_size; j++) {
            for (int k = 0; k < 4; k++) {
                grp[i][j][k] = 9999999;
            }
        }
    }

    dfs(board, 0, 0, 0, -1);

    answer = minCost;
    return answer;
}