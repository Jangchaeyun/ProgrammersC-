#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = 0, idx = 0;
	while (idx < s.size())
	{
		int cnt = 1;
		char c = s[idx++];
		while (idx < s.size() && cnt)
		{
			if (s[idx] != c) cnt--;
			else cnt++;
			idx++;
		}
		answer++;
	}
	return answer;
}