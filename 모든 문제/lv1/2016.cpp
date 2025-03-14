#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	string day[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
	int MON[13] = { 0 ,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int cnt = 0;
	for (int i = 1; i < a; i++)
		cnt += MON[i];
	cnt += b - 1;
	answer += day[cnt % 7];

	return answer;
}