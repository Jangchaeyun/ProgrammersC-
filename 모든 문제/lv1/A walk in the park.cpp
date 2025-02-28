#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct {
	int x, y;
}box;

box moveD[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
map<char, int> mapping = { { 'N', 0 }, { 'S', 1 }, { 'W', 2 }, { 'E', 3 } };

vector<int> solution(vector<string> park, vector<string> routes) {
	pair<int, int> loc;

	int H = park.size();
	int W = park[0].size();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (park[i][j] == 'S') {
				loc = { i, j };
				break;
			}
		}
	}

	for (const auto& route : routes) {
		char op = mapping[route[0]];
		int n = route[2] - 48;

		int nx = loc.first;
		int ny = loc.second;

		while (n--) {
			nx += moveD[op].x;
			ny += moveD[op].y;

			if ((nx < 0 || H <= nx || ny < 0 || W <= ny) || park[nx][ny] == 'X')
				break;
		}
		if (n < 0) loc = { nx, ny };
	}
	return { loc.first, loc.second };
}