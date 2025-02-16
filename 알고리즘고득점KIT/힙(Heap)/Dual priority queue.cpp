#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	int cnt = 0;
	multiset<int, less<int>> ms;
	char c; int n;
	for (int i = 0; i < operations.size(); i++)
	{
		stringstream ss(operations[i]);
		ss >> c;
		ss >> n;
		if (c == 'I')
			ms.insert(n);
		else {
			if (n == 1 and !ms.empty())
				ms.erase(--ms.end());
			else if (n == -1 and !ms.empty())
				ms.erase(ms.begin());
		}
	}
	if (ms.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(*(--ms.end()));
		answer.push_back(*ms.begin());
	}
	return answer;
}