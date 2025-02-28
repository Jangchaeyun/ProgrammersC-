#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	for (int i = 0; i < targets.size(); i++)
	{
		answer.push_back(0);
		for (int j = 0; j < targets[i].size(); j++)
		{
			char c = targets[i][j];
			int type = 101, flag = 1;
			for (int k = 0; k < keymap.size(); k++)
			{
				for (int l = 0; l < keymap[k].size(); l++)
				{
					if (keymap[k][l] == c)
					{
						type = min(type, l + 1);
						flag = 0;
						break;
					}
				}
			}
			if (flag)
			{
				answer[i] = -1;
				break;
			}
			answer[i] += type;
		}
	}
	return answer;
}