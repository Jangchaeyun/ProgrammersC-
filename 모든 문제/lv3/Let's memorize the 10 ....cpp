#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int num, count;
};

bool compare(Point a, Point b) {
	if (a.count == b.count) return a.num < b.num;
	return a.count > b.count;
}

vector<int> solution(int e, vector<int> starts) {
	vector<Point> dp(e + 1);
	for (int i = 1; i <= e; i++) dp[i] = { i, 0 };

	for (int i = 2; i <= e; i++)
		for (int j = 1; j <= e; j++) {
			if (i * j > e) break;
			dp[i * j].count++;
		}
	sort(dp.begin(), dp.end(), compare);
	vector<int> answer;

	for (auto it : starts) {
		int s = it;

		for (int i = 0; i <= e; i++) {
			if (dp[i].num >= s) {
				answer.push_back(dp[i].num);
				break;
			}
		}
	}
	
	return answer;
}