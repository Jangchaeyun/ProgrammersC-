#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;
	deque<string> dq;
	for (auto city : cities) {
		bool cache = false;
		for (int i = 0; i < city.size(); i++)
			if (isupper(city[i])) city[i] += 32;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == city)
			{
				cache = true;
				dq.erase(dq.begin() + i);
				dq.push_front(city);
				answer += 1;
			}
		}
		if (!cache)
		{
			dq.push_front(city);
			if (dq.size() > cacheSize) dq.pop_back();
			answer += 5;
		}
	}
	return answer;
}