#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<int, pair<int, int>> pos;
vector<map<pair<int, int>, int>> path_count;

int answer;

void movePath(vector<int>& r) {
    pair<int, int> final;
    int time = 0;
    for (int i = 0; i < r.size() - 1; i++) {

        pair<int, int>s = pos[r[i]];
        pair<int, int>e = pos[r[i + 1]];
        final = e;

        while (s != e) {
            path_count[time][s]++;
            if (path_count[time][s] == 2)answer++;
            int dy = s.first - e.first;
            int dx = s.second - e.second;

            if (dy != 0) {
                if (dy > 0)s.first--;
                else s.first++;
            }
            else if (dx != 0) {
                if (dx > 0)s.second--;
                else s.second++;
            }
            time++;
        }
    }
    path_count[time][final]++;
    if (path_count[time][final] == 2)answer++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {

    for (int i = 0; i < points.size(); i++) {
        pos[i + 1] = { points[i][0],points[i][1] };
    }
    path_count.resize(100001);

    for (auto p : routes) {
        movePath(p);
    }

    return answer;
}