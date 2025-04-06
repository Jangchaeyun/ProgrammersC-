#include <string>
#include <vector>
#include <queue>
#define MAX 999999
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool visited[4][4][2] = { false };
bool redEnd, blueEnd;
int map[4][4] = { 0 };
int width, height;

struct Point {
    int x, y;
};

Point getNext(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    return { nx,ny };
}

bool isPossible(Point cntRed, Point red,
    Point cntBlue, Point blue) {
    if (red.x < 0 || red.y < 0 || red.x >= height || red.y >= width
        || blue.x < 0 || blue.y < 0 || blue.x >= height || blue.y >= width
        || map[red.x][red.y] == 5 || map[blue.x][blue.y] == 5) return false;

    if ((cntRed.x == blue.x && cntRed.y == blue.y)
        && (cntBlue.x == red.x && cntBlue.y == red.y)) return false;

    if ((!redEnd && visited[red.x][red.y][0])
        || (!blueEnd && visited[blue.x][blue.y][1])) return false;

    if (red.x == blue.x && red.y == blue.y) return false;
    return true;
}

int backtracking(Point red, Point blue, int result) {
    if (redEnd && blueEnd) return result;
    int answer = MAX;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Point nRed = (!redEnd) ? getNext(red.x, red.y, i) : red;
            Point nBlue = (!blueEnd) ? getNext(blue.x, blue.y, j) : blue;

            if (!isPossible(red, nRed, blue, nBlue)) continue;
            visited[nRed.x][nRed.y][0] = true;
            visited[nBlue.x][nBlue.y][1] = true;
            if (map[nRed.x][nRed.y] == 3) redEnd = true;
            if (map[nBlue.x][nBlue.y] == 4) blueEnd = true;

            answer = min(answer, backtracking(nRed, nBlue, result + 1));

            redEnd = false;
            blueEnd = false;
            visited[nRed.x][nRed.y][0] = false;
            visited[nBlue.x][nBlue.y][1] = false;
        }
    }
    return answer;
}

int solution(vector<vector<int>> maze) {
    Point cntRed, cntBlue;
    height = maze.size();
    width = maze[0].size();
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            map[i][j] = maze[i][j];

            if (maze[i][j] == 1) cntRed = { i,j };
            else if (maze[i][j] == 2) cntBlue = { i,j };
        }
    }

    visited[cntRed.x][cntRed.y][0] = true;
    visited[cntBlue.x][cntBlue.y][1] = true;

    int answer = backtracking(cntRed, cntBlue, 0);
    return (answer == MAX) ? 0 : answer;
    return answer;
}