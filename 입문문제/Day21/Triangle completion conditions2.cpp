#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
	int answer = 0;

	sort(sides.begin(), sides.end());

	for (int i = sides[1] - sides[0] + 1; i < sides[0] + sides[1]; i++) {
		answer++;
	}
	return answer;
}