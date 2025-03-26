#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> place;

typedef struct {
    int x, y, d;
}info;

typedef struct {
    int x, y;
}box;

box moveD[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

bool checkDistance(int x, int y) {
    bool visited[5][5] = { false, };
    queue<info> q;
    visited[x][y] = true;
    q.push({ x, y, 0 });

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int d = q.front().d;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + moveD[i].x;
            int ny = cy + moveD[i].y;

            if (nx < 0 || 5 <= nx || ny < 0 || 5 <= ny)
                continue;

            if (visited[nx][ny] || place[nx][ny] == 'X')
                continue;

            if (place[nx][ny] == 'P') {
                if (d + 1 <= 2) {
                    return false;
                }
            }

            visited[nx][ny] = true;
            q.push({ nx, ny, d + 1 });
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto p : places) {
        bool result = true;
        place = p;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (place[i][j] == 'P') {
                    if (!checkDistance(i, j)) {
                        result = false;
                        break;
                    }
                }
            }

            if (!result) break;
        }

        if (!result) answer.push_back(0);
        else answer.push_back(1);
    }

    return answer;
}