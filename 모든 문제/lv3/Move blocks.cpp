#include <string>
#include <vector>
#include <queue>
using namespace std;

static int N;

typedef struct Node {
    int ly, lx, ry, rx;
    Node(int a, int b, int c, int d) {
        this->ly = a;   this->lx = b;
        this->ry = c;   this->rx = d;
    }
}Node;

inline bool isSafe(Node cur) {
    return ((0 <= cur.ly && cur.ly < N) && (0 <= cur.lx && cur.lx < N) &&
        ((0 <= cur.ry && cur.ry < N) && (0 <= cur.rx && cur.rx < N)));
}

vector<Node> getNextPos(Node cur, vector<vector<int>> board) {
    const int d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    vector<Node> ret;

    for (int i = 0; i < 4; ++i) {
        Node nextPos(cur.ly + d[i][0], cur.lx + d[i][1], cur.ry + d[i][0], cur.rx + d[i][1]);
        if (isSafe(nextPos) && board[nextPos.ly][nextPos.lx] == 0 && board[nextPos.ry][nextPos.rx] == 0)
            ret.push_back(nextPos);
    }
    int offset[2] = { -1, 1 };
    if (cur.ly == cur.ry) {
        for (int i = 0; i < 2; ++i) {
            int newLy = cur.ly + offset[i], newRy = cur.ry + offset[i];
            if (isSafe(Node(newLy, cur.lx, newRy, cur.rx)) && !board[newLy][cur.lx] && !board[newRy][cur.rx]) {
                ret.push_back(Node(newLy, cur.lx, cur.ly, cur.lx));
                ret.push_back(Node(newRy, cur.rx, cur.ry, cur.rx));
            }
        }
    }
    else {
        for (int i = 0; i < 2; ++i) {
            int newLx = cur.lx + offset[i], newRx = cur.rx + offset[i];
            if (isSafe(Node(cur.ly, newLx, cur.ry, newRx)) && !board[cur.ly][newLx] && !board[cur.ry][newRx]) {
                ret.push_back(Node(cur.ly, newLx, cur.ly, cur.lx));
                ret.push_back(Node(cur.ry, newRx, cur.ry, cur.rx));
            }
        }
    }
    return ret;
}

int solution(vector<vector<int>> board) {
    N = board.size();
    queue<pair<Node, int>> q;
    q.push({ Node(0, 0, 0, 1), 0 });
    vector<Node> visited;
    visited.push_back(Node(0, 0, 0, 1));

    while (!q.empty()) {
        Node pos = q.front().first;
        int cost = q.front().second;
        q.pop();
        if ((pos.ly == N - 1 && pos.lx == N - 1) || (pos.ry == N - 1 && pos.rx == N - 1))
            return cost;
        vector<Node> nextPos = getNextPos(pos, board);
        for (int i = 0; i < nextPos.size(); ++i) {
            bool safeFlag = true;
            for (int j = 0; j < visited.size(); ++j)
                if (nextPos[i].ly == visited[j].ly && nextPos[i].lx == visited[j].lx
                    && nextPos[i].ry == visited[j].ry && nextPos[i].rx == visited[j].rx) {
                    safeFlag = false;
                    break;
                }
            if (safeFlag) {
                q.push({ nextPos[i], cost + 1 });
                visited.push_back(nextPos[i]);
            }
        }
    }
    return 0;
}