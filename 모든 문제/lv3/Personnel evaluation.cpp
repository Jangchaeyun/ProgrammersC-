#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores) {
	int answer = scores.size() + 1, wanho = scores[0][0] + scores[0][1], size = scores.size();
	for (auto c : scores)
		if (scores[0][0] < c[0] && scores[0][1] < c[1]) return -1;
	sort(scores.begin() + 1, scores.end());
	for (int i = 1; i < size; i++)
	{
		if (wanho >= scores[i][0] + scores[i][1]) continue;
		for (int j = i + 1; j < size; j++)
		{
			if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
			{
				answer--;
				break;
			}
		}
	}
	for (auto c : scores) if (wanho >= c[0] + c[1]) answer--;
	return answer;
}