#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Point {
    int x;
    int y;
};

vector<vector<bool> > check;
vector<vector<Point> > puzzleList;
vector<vector<Point> > emptyList;


vector<vector<bool>> rotateOnce(vector<vector<bool> > origin) {

    int c = origin.size();
    int r = origin.size();

    vector<vector<bool>> board;
    vector<bool> row(r);

    for (int i = 0; i < c; i++) board.push_back(row);

    for (int i = 0; i < origin.size(); i++) {
        for (int j = 0; j < origin[i].size(); j++) {
            board[origin.size() - j - 1][i] = origin[i][j];
        }
    }
    return board;
}

vector<vector<bool>> fillBoard(vector<Point> p, vector<vector<bool> > board) {
    for (int i = 0; i < p.size(); i++) {
        int x = p[i].x;
        int y = p[i].y;
        board[x][y] = false;
    }
    return board;
}

vector<Point> getPuzzle(int sx, int sy, vector<vector<bool>> select) {
    int dx[] = { 0,0,-1,1 };
    int dy[] = { -1,1,0,0 };

    queue<Point> q;
    vector<Point> list;
    check[sx][sy] = true;
    Point p = { sx,sy };
    q.push(p);
    list.push_back(p);


    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= select.size() || ny >= select.size()
                || check[nx][ny] || !select[nx][ny]) continue;
            check[nx][ny] = true;
            Point np = { nx,ny };
            q.push(np);
            list.push_back(np);
        }
    }
    return list;
}

vector<Point> rePos(vector<Point> p) {
    int minX = p[0].x;
    int minY = p[0].y;

    for (int i = 1; i < p.size(); i++) {
        minX = min(minX, p[i].x);
        minY = min(minY, p[i].y);
    }

    for (int i = 0; i < p.size(); i++) {
        p[i].x -= minX;
        p[i].y -= minY;
    }
    return p;

}

int comparePuzzle(vector<Point> a, vector<Point> b) {
    int answer = 0;
    a = rePos(a);
    b = rePos(b);

    int count = 0;
    if (a.size() != b.size()) return 0;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i].x == b[j].x && a[i].y == b[j].y) {
                count++;
                break;
            }
        }
    }
    if (count == a.size()) return a.size();
    else return 0;
}

int solution(vector<vector<int> > game_board, vector<vector<int> > table) {
    vector<vector<bool> > board;
    vector<vector<bool> > puzzles;
    for (int i = 0; i < table.size(); i++) {
        vector<bool> v1;
        vector<bool> v2;
        vector<bool> v3;
        for (int j = 0; j < table[i].size(); j++) {
            v1.push_back(!game_board[i][j]);
            v2.push_back(table[i][j]);
            v3.push_back(false);
        }
        board.push_back(v1);
        puzzles.push_back(v2);
        check.push_back(v3);
    }

    for (int i = 0; i < puzzles.size(); i++)
        for (int j = 0; j < puzzles[i].size(); j++)
            if (!check[i][j] && puzzles[i][j]) puzzleList.push_back(getPuzzle(i, j, puzzles));

    int count = 4;
    int answer = 0;
    fill(check.begin(), check.end(), vector<bool>(check.size(), false));

    while (count--) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board.size(); j++)
                if (board[i][j] && !check[i][j])
                    emptyList.push_back(getPuzzle(i, j, board));

        for (int i = 0; i < puzzleList.size(); i++) {
            for (int j = 0; j < emptyList.size(); j++) {
                int val = comparePuzzle(puzzleList[i], emptyList[j]);
                if (val != 0) {
                    answer += val;
                    board = fillBoard(emptyList[j], board);
                    puzzleList.erase(puzzleList.begin() + i);
                    emptyList.erase(emptyList.begin() + j);
                    i--;
                    break;
                }
            }
        }
        board = rotateOnce(board);

        fill(check.begin(), check.end(), vector<bool>(check.size(), false));
    }
    return answer;
}