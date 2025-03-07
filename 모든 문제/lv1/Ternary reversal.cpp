#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;

	string temp = "";
	while (n)
	{
		temp = to_string(n % 3) + temp;
		n /= 3;
	}

	reverse(temp.begin(), temp.end());

	int tri = 1;
	for (int i = temp.length() - 1; i > -1; i--)
	{
		answer += (temp[i] - '0') * tri;
		tri *= 3;
	}
	return answer;
}