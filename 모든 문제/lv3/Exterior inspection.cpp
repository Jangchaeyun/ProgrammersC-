#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 1e8;
	int w_size = weak.size();

    for (int i = 0; i < w_size - 1; ++i) {
        weak.push_back(weak[i] + n);
    }

    sort(dist.begin(), dist.end());

    do {
        for (int i = 0; i < w_size; ++i) {
            int start = weak[i];
            int end = weak[i + w_size - 1];

            for (int j = 0; j < dist.size(); ++j) {
                start += dist[j];

                if (start >= end) {
                    answer = min(answer, j + 1);
                    break;
                }
                for (int z = i + 1; z < i + w_size; ++z) {
                    if (weak[z] > start) {
                        start = weak[z];
                        break;
                    }
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));

    if (answer == 1e8) return -1;

    return answer;
}