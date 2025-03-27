#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool check(string str) {
	stack<char> st;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') st.push('(');
		else {
			if (!st.empty() && st.top() == '(') st.pop();
			else return false;
		}
	}
	return true;
}

string solution(string p) {
	string answer = "", u = "", v = "";
	int l = 0, r = 0;

	if (p == "") return "";

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') l++;
		else r++;

		if (l == r) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}

	if (check(u)) {
		v = solution(v);
		answer = u + v;
		return answer;
	}

	else {
		answer = "(" + solution(v) + ")";

		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(') answer += ")";
			else answer += "(";
		}
		return answer;
	}
}