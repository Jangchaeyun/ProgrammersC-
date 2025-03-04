#include <string>
#include <vector>
#include <map>

using namespace std;

int score[8] = { 0, 3, 2, 1, 0, 1, 2, 3 };

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<char, int> surv_eim;

	for (int i = 0; i < survey.size(); i++) {
		surv_eim[survey[i][choices[i] / 4]] += score[choices[i]];
	}

	answer += surv_eim['R'] >= surv_eim['T'] ? "R" : "T";
	answer += surv_eim['C'] >= surv_eim['F'] ? "C" : "F";
	answer += surv_eim['J'] >= surv_eim['M'] ? "J" : "M";
	answer += surv_eim['A'] >= surv_eim['N'] ? "A" : "N";

	return answer;
}