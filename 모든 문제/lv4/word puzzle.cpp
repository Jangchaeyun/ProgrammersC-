#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CanMake(int st, string& t, string cmpstr)
{
	if (st + cmpstr.length() > t.length())
	{
		return false;
	}
	for (int i = 0; i < cmpstr.size(); i++)
	{
		if (cmpstr[i] != t[st + i])
		{
			return false;
		}
	}
	return true;
}

int solution(vector<string> strs, string t) {
	int answer = 0;
	
	vector<int> DP(t.length(), -1);
	for (int i = 0; i < strs.size(); i++)
	{
		if (CanMake(0, t, strs[i]))
		{
			DP[strs[i].length() - 1] = 1;
		}
	}
	for (int i = 0; i < DP.size(); i++)
	{
		if (DP[i] != -1)
		{
			for (int j = 0; j < strs.size(); j++)
			{
				if (CanMake(i + 1, t, strs[j]))
				{
					if (DP[i + strs[j].length()] == -1)
					{
						DP[i + strs[j].length()] = DP[i] + 1;
					}
					else
					{
						DP[i + strs[j].length()] = min(DP[i + strs[j].length()], DP[i] + 1);
					}
				}
			}
		}
	}
	
	return DP[t.length() - 1];
}