#include <string>
#include <map>

using namespace std;

map<string, pair<int, int>> mp;

int solution(string str1, string str2) {
	int answer = 0;
	int interNum = 0, unionNum = 0;
	double num = 0;

	for (int i = 0; i < str1.size(); i++) str1[i] = tolower(str1[i]);
	for (int i = 0; i < str2.size(); i++) str2[i] = tolower(str2[i]);

	for (int i = 0; i < str1.size() - 1; i++)
		if (isalpha(str1[i]) && isalpha(str1[i + 1]))
			mp[str1.substr(i, 2)].first++;

	for (int i = 0; i < str2.size() - 1; i++) {
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
			mp[str2.substr(i, 2)].second++;
	}

	for (auto it : mp) {
		interNum += min(it.second.first, it.second.second);
		unionNum += max(it.second.first, it.second.second);
	}

	if (interNum == 0 && unionNum == 0) num = 1.0;
	else num = double(interNum) / double(unionNum);

	answer = num * 65536;

	return answer;
}