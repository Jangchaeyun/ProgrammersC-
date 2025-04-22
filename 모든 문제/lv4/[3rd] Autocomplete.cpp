#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
	int ans = 1, pre = 0;

	sort(words.begin(), words.end());

	string pre_word = words[0];

	for (int cur = 1; cur < words.size(); cur++) {
		int idx = 0;

		for (; idx <= words[cur].size(); idx++) {
			if (idx >= pre_word.size()) {
				ans += pre_word.size() - pre - 1;
				ans += idx + 1;
				break;
			}
			if (words[cur][idx] != pre_word[idx]) {
				if (idx > pre) ans += idx - pre;
				ans += idx + 1;
				break;
			}
		}

		pre = idx;
		pre_word = words[cur];
	}
	return ans;
}