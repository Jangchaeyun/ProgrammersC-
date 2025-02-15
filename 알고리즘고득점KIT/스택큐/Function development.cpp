#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> left, answer;

	for (int i = 0; i < progresses.size(); ++i) {
		int more = (100 - progresses[i]) / speeds[i];
		int rest = (100 - progresses[i]) % speeds[i];
		if (rest > 0) more++;
		left.push_back(more);
	}
	int max_num = left[0], count = 1;
	for (int i = 1; i < left.size(); ++i) {
		if (max_num >= left[i]) count++;
		else {
			answer.push_back(count);
			max_num = left[i];
			count = 1;
		}
	}
	answer.push_back(count);
	return answer;
}