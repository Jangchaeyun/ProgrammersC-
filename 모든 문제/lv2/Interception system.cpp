#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets)
{
	int answer = 0, idx = 0;
	sort(targets.begin(), targets.end());
	while (idx < targets.size())
	{
		int end = targets[idx++][1];
		answer++;
		while (idx < targets.size() && targets[idx][0] < end)
		{
			if (targets[idx][1] < end) end = targets[idx][1];
			idx++;
		}
	}
	return answer;
}