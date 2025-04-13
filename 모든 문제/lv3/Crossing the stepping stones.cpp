#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int mid, int k, vector<int>& stones) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] <= mid) cnt++;
		else cnt = 0;

		if (cnt >= k) return false;
	}
	return true;
}

int solution(vector<int> stones, int k) {
	int s = 1;
	int e = *max_element(stones.begin(), stones.end());
	int mid;

	while (s <= e) {
		mid = (s + e) / 2;

		if (isPossible(mid, k, stones)) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}