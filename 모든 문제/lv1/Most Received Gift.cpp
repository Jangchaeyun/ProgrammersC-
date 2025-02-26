#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, int> FM;
vector<vector<int>>graph;
vector<int>giftScore;

void splitFunc(string str)
{
	istringstream is;
	is.str(str);
	vector<string> ans;
	string sttt;
	while (getline(is, sttt, ' '))
	{
		ans.push_back(sttt);
	}
	graph[FM[ans[0]]][FM[ans[1]]] += 1;
	graph[FM[ans[1]]][FM[ans[0]]] -= 1;
	giftScore[FM[ans[0]]] += 1;
	giftScore[FM[ans[1]]] -= 1;
}

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;
	giftScore = vector<int>(friends.size(), 0);
	for (int i = 0; i < friends.size(); i++)
	{
		FM.insert({ friends[i], i });
	}
	graph = vector<vector<int>>(friends.size(), vector<int>(friends.size(), 0));
	for (int i = 0; i < gifts.size(); i++)
	{
		splitFunc(gifts[i]);
	}

	for (int i = 0; i < friends.size(); i++)
	{
		int nowGift = 0;
		for (int j = 0; j < friends.size(); j++)
		{
			if (graph[i][j] > 0)
			{
				nowGift += 1;
			}
			else if (graph[i][j] == 0)
			{
				if (giftScore[i] > giftScore[j])
				{
					nowGift += 1;
				}
			}
		}

		if (nowGift > answer)
		{
			answer = nowGift;
		}
	}
	return answer;
}