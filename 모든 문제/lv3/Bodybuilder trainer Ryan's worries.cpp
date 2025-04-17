#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<vector<int>> timetable) {
    vector<int> count(1321);
    for (auto& time : timetable) {
        for (int i = time.front(); i <= time.back(); i++) {
            count[i]++;
        }
    }

    int people = *max_element(count.begin(), count.end());
    if (people <= 1) {
        return 0;
    }

    for (int d = 2 * n - 2; d > 0; d--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<pair<int, int>> lock({ {i, j} });
                for (int y = i; y < n; ++y) {
                    for (int x = 0; x < n; ++x) {
                        if (y != i || x > j) {

                            bool canPush = true;
                            for (auto& p : lock) {
                                int dist = abs(p.first - y) + abs(p.second - x);
                                if (dist < d) {
                                    canPush = false;
                                    break;
                                }
                            }

                            if (canPush) {
                                lock.emplace_back(y, x);
                                if (people == lock.size()) {
                                    return d;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}