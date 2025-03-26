#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (int i = 0; i < numbers.size(); i++)
	{
		long long Num = numbers[i];
		if (Num % 2 == 0) answer.push_back(Num + 1);
		else
		{
			long long LastZero = (Num + 1) & (-Num);
			long long Result = (Num | LastZero) & (~(LastZero >> 1));
			answer.push_back(Result);
		}
	}
	return answer;
}