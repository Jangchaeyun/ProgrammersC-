#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

int TimeToInt(string t)
{
	return (60 * stoi(t.substr(0, 2))) + stoi(t.substr(3));
}

bool SortPlans(vector<string> v1, vector<string> v2)
{
	return TimeToInt(v1[1]) < TimeToInt(v2[1]);
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	stack<pair<string, int>> paused_plans;

	sort(plans.begin(), plans.end(), SortPlans);

	int cur_time = TimeToInt(plans[0][1]);
	int next_time = TimeToInt(plans[1][1]);
	int cur_subject = 0;

	while (cur_subject < plans.size() || !paused_plans.empty())
	{
		if (!paused_plans.empty())
		{
			if (cur_subject == plans.size())
			{
				answer.emplace_back(paused_plans.top().first);
				paused_plans.pop();
				continue;
			}

			if (cur_time < next_time)
			{
				int remain_time = paused_plans.top().second;
				int avaialable_time = next_time - cur_time;

				if (remain_time <= avaialable_time)
				{
					answer.emplace_back(paused_plans.top().first);
					paused_plans.pop();
					cur_time += remain_time;
				}
				else
				{
					paused_plans.top().second = remain_time - avaialable_time;
					cur_time = next_time;
				}
				continue;
			}
		}

		cur_time = TimeToInt(plans[cur_subject][1]) + stoi(plans[cur_subject][2]);
		next_time = cur_subject + 1 >= plans.size() ? 1440 : TimeToInt(plans[cur_subject + 1][1]);

		if (cur_time > next_time)
		{
			paused_plans.push({ plans[cur_subject][0], cur_time - next_time });
			cur_time = next_time;
		}
		else
		{
			answer.emplace_back(plans[cur_subject][0]);
		}
		++cur_subject;
	}
	return answer;
}