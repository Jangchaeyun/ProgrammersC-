#include <cmath>

using namespace std;

int answer = 0;
void calc(int nowNum, int plusCnt, int multiCnt)
{
	if (plusCnt < (multiCnt - 1) * 2)
	{
		return;
	}
	int n;
	while (nowNum >= 3) {
		if (nowNum == 3) {
			if (plusCnt % 2 == 0) {
				if ((plusCnt / 2) == multiCnt)
				{
					answer++;
				}
			}
			return;
		}
		n = plusCnt / 2 - multiCnt;
		if (pow(3, n) > nowNum)
		{
			return;
		}
		if (nowNum % 3 == 0)
		{
			calc(nowNum / 3, plusCnt, multiCnt + 1);
		}
		nowNum -= 1;
		plusCnt += 1;
	}
}

int solution(int n) {
	answer = 0;
	calc(n - 2, 2, 1);
	return answer;
}