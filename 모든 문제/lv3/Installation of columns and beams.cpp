#include <string>
#include <vector>

using namespace std;

int Bframe[101][101][2];

bool check_build_struct(int x, int y, int a, int n) {
    if (a == 0) {
        if (y == 0) return true;
        if (x > 0 && Bframe[x - 1][y][1]) return true;
        if (y < n && Bframe[x][y][1]) return true;
        if (y > 0 && Bframe[x][y - 1][0]) return true;
    }
    else {
        if (y > 0 && Bframe[x][y - 1][0]) return true;
        if (x < n && y > 0 && Bframe[x + 1][y - 1][0]) return true;
        if (x > 0 && x < n && Bframe[x - 1][y][1] && Bframe[x + 1][y][1]) return true;
    }

    return false;
}

bool check_remove_struct(int x, int y, int a, int n) {
    Bframe[x][y][a] = 0;

    if (a == 0) {
        if (y < n && Bframe[x][y + 1][0] && !check_build_struct(x, y + 1, 0, n)) return false;
        if (y < n && Bframe[x][y + 1][1] && !check_build_struct(x, y + 1, 1, n)) return false;
        if (x > 0 && y < n && Bframe[x - 1][y + 1][1] && !check_build_struct(x - 1, y + 1, 1, n)) return false;
    }
    else {
        if (Bframe[x][y][0] && !check_build_struct(x, y, 0, n)) return false;
        if (x < n && Bframe[x + 1][y][0] && !check_build_struct(x + 1, y, 0, n)) return false;

        if (x > 0 && Bframe[x - 1][y][1] && !check_build_struct(x - 1, y, 1, n)) return false;
        if (x < n && Bframe[x + 1][y][1] && !check_build_struct(x + 1, y, 1, n)) return false;
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (const auto& frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2];
        int b = frame[3];

        if (b == 0) {
            if (!check_remove_struct(x, y, a, n)) {
                Bframe[x][y][a] = 1;
            }
        }
        else {
            if (check_build_struct(x, y, a, n)) {
                Bframe[x][y][a] = 1;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (Bframe[i][j][0]) {
                answer.push_back({ i, j, 0 });
            }
            if (Bframe[i][j][1]) {
                answer.push_back({ i, j, 1 });
            }
        }
    }

    return answer;
}
