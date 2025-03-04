#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> mpX;
map<char, int> mpY;

string solution(string X, string Y) {
	string answer = "";

	for (int i = 0; i < X.size(); i++) mpX[X[i]]++;
	for (int i = 0; i < Y.size(); i++) mpY[Y[i]]++;

	for (int i = 9; i >= 0; i--) {
		int num = min(mpX[i + '0'], mpY[i + '0']);
		for (int j = 0; j < num; j++)
			answer += i + '0';
	}

	if (answer == "") return "-1";
	else if (answer[0] == '0') return "0";
	else return answer;
}