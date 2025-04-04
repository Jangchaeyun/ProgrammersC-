#include <string>
#include <vector>

using namespace std;

long long findTitle(long long& num) {
	if (num == 1) return 0;
	long long i = 2, res = 1;
	while (i * i <= num) {
		if (num % i == 0) {
			res = i;
			if (num / i <= 10000000) return (num / i);
		}
		i++;
	}
	return res;
}

vector<int> solution(long long begin, long long end) {
	vector<int> answer;
	for (; begin <= end; begin++) {
		answer.push_back(findTitle(begin));
	}
	return answer;
}