#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
	vector<pair<int, int>> cords;
	for (int i = 0; i < line.size(); i++)
	{
		for (int j = i + 1; j < line.size(); j++) {
			int adbc = line[i][0] * line[j][1] - line[i][1] * line[j][0];
			if (adbc)
			{
				long long x = (1LL * line[i][1] * line[j][2] - 1LL * line[i][2] * line[j][1]);
				long long y = (1LL * line[i][2] * line[j][0] - 1LL * line[i][0] * line[j][2]);
				if (x % adbc == 0 && y % adbc == 0) cords.push_back({ x / adbc,y / adbc });
			}
		}
	}

	sort(cords.begin(), cords.end());
	cords.erase(unique(cords.begin(), cords.end()), cords.end());
	int x_min = INT32_MAX, x_max = INT32_MIN, y_min = INT32_MAX, y_max = INT32_MIN;
	for (auto cord : cords)
	{
		x_min = min(x_min, cord.first);
		x_max = max(x_max, cord.first);
		y_min = min(y_min, cord.second);
		y_max = max(y_max, cord.second);
	}
	int n = y_max - y_min, m = x_max - x_min;
	vector<string> answer;
	for (int i = 0; i <= n; i++)
	{
		string tmp(m + 1, '.');
		answer.push_back(tmp);
	}
	for (auto cord : cords) answer[-cord.second + y_max][cord.first - x_min] = '*';
	return answer;
}