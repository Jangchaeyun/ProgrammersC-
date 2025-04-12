#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
	vector<int> left(a.size()), right(a.size());
    int lMin, rMin;
    lMin = left[0] = a[0];
    rMin = right[a.size() - 1] = a[a.size() - 1];

    for (int i = 1; i < a.size() - 1; i++) {
        lMin = min(lMin, a[i]);
        left[i] = lMin;
    }
    for (int i = a.size() - 1; i >= 1; i--) {
        rMin = min(rMin, a[i]);
        right[i] = rMin;
    }
    int answer = 2;
    if (a.size() == 1) return 1;

    for (int i = 1; i < a.size() - 1; i++) {
        if (left[i - 1] < a[i] && right[i + 1] < a[i]) continue;
        answer++;
    }

    return answer;

}