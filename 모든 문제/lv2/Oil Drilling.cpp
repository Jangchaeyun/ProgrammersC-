#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    Pos(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};

int solution(vector<vector<int>> land) {
    int dirX[4] = { 1, -1, 0, 0 };
    int dirY[4] = { 0, 0, 1, -1 };
    int n = land.size();
    int m = land[0].size();
    int answer = 0;
    int num = 1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));   
    vector<vector<int>> oils(n, vector<int>(m, 0));             
    map<int, int> oilBlocks;                                    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] || land[i][j] != 1) continue;
            queue<Pos> q;
            q.push(Pos(i, j));
            visited[i][j] = true;
            oils[i][j] = num;

            int oil = 0;
            while (!q.empty()) {
                Pos curr = q.front();
                q.pop();
                oil++;
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = curr.x + dirX[dir];
                    int ny = curr.y + dirY[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (visited[nx][ny] || land[nx][ny] != 1) continue;
                    q.push(Pos(nx, ny));
                    visited[nx][ny] = true;
                    oils[nx][ny] = num;
                }
            }

            oilBlocks[num++] = oil;
        }
    }

    for (int j = 0; j < m; ++j) {
        int sum = 0;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(oils[i][j]);
        }
        for (int num : s) {
            sum += oilBlocks[num];
        }

        if (sum > answer) answer = sum;
    }

    return answer;
}