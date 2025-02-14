#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
	int ans = 0;
	while (chicken >= 10) {
		chicken -= 10;
		ans++;
		chicken++;
	}
	return ans;
}