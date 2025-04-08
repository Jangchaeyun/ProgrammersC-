#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

char map[4][3] = { {'1','2','3'},
                {'4','5','6'},
                {'7','8','9'},
                {'*','0','#'} };
vector<Point> input;
int dp[100001][10][10];

int getWeight(Point pos, Point target) {
    int sx = pos.x;
    int sy = pos.y;

    int x = target.x;
    int y = target.y;

    if (sx == x && sy == y) return 1;
    if (sx == x || sy == y) return abs((sx - x) * 2 + (sy - y) * 2);
    if (abs(sx - x) == abs(sy - y)) return abs(sx - x) * 3;

    int nx = abs(sx - x);
    int ny = abs(sy - y);
    int diag = min(nx, ny);
    int line = max(nx, ny);

    return diag * 3 + (line - diag) * 2;
}

int startGame(Point left, Point right, int idx) {
    if (idx >= input.size()) return 0;

    if (left.x == right.x && left.y == right.y) return 9999999;
    int l_num = map[left.x][left.y] - '0';
    int r_num = map[right.x][right.y] - '0';

    if (dp[idx][l_num][r_num] != 0) return dp[idx][l_num][r_num];

    int l_weight = getWeight(left, input[idx]);
    int r_weight = getWeight(right, input[idx]);

    int v1 = l_weight + startGame(input[idx], right, idx + 1);
    int v2 = r_weight + startGame(left, input[idx], idx + 1);

    return dp[idx][l_num][r_num] = min(v1, v2);
}

int solution(string numbers) {
    int answer = 0;
    for (int k = 0; k < numbers.length(); k++) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                if (map[i][j] == numbers[k]) input.push_back({ i,j });
    }
    Point left = { 1,0 }; 
    Point right = { 1,2 };
    answer = startGame(left, right, 0);
    return answer;
}