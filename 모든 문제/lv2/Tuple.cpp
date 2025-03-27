#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
	unordered_map<int, int> m;
	for (int i = 2; i < s.size(); i++) {
		if (isdigit(s[i])) {
			m[stoi(s.substr(i))]++;
			while (isdigit(s[i]))
				i++;
		}
	}
	int size = m.size();
	vector<int> answer(size);
	for (auto c : m) answer[size - c.second] = c.first;
	return answer;
}