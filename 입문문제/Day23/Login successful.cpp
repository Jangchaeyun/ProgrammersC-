#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> mp;

string solution(vector<string> id_pw, vector<vector<string>> db) {
	string answer = "fail";

	for (int i = 0; i < db.size(); i++) mp[db[i][0]] = db[i][1];

	for (int i = 0; i < mp.size(); i++) {
		if (mp.find(id_pw[0]) != mp.end()) {
			if (mp[id_pw[0]] == id_pw[1]) {
				answer = "login";
				break;
			}

			else if (mp[id_pw[0]] != id_pw[1]) {
				answer = "wrong pw";
				break;
			}
		}

		else answer = "fail";
	}

	return answer;
}