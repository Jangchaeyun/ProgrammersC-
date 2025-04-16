#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[2501][2501] = { 0, };
int arr[2501] = { 0, };
int solution(string s)
{
	int answer = 0;
	for (int i = 0; i < s.length(); i++) arr[i + 1] = s[i];

	for (int i = s.length(); i > 0; i--) {
		for (int j = i; j <= s.length(); j++) {
			if (i == j) dp[i][j] = 1;

			else if (arr[i] == arr[j] && dp[i + 1][j - 1] != -1) {
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}

			else dp[i][j] = -1;

			answer = max(answer, dp[i][j]);
		}
	}

	return answer;
}