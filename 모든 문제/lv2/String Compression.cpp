#include <string>

using namespace std;

int solution(string s) {
	int answer = 99999;
	int count = 1;
	string str;
	string tmp = "";

	if (s.length() == 1) {
		return 1;
	}

	for (int i = 1; i <= s.length() / 2; i++) {
		str = s.substr(0, i);
		for (int j = i; j <= s.length(); j += i) {
			if (s.substr(j, i).compare(str) == 0) {
				count++;
			}
			else {
				if (count > 1) {
					tmp += to_string(count) + str;
					str = s.substr(j, i);
				}
				else {
					tmp += str;
					str = s.substr(j, i);
				}
				count = 1;
			}
		}
		tmp += str;
		if (answer > tmp.length()) answer = tmp.length();
		tmp.clear();
	}
	return answer;
}