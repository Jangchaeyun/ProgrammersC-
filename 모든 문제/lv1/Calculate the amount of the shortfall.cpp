#include <string>
#include <vector>

using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = 0;
	long long n = price;

	for (int i = 1; i <= count; i++) answer += n * i;

	if (answer - money <= 0) answer = 0;
	else answer = answer - money;

	return answer;
}