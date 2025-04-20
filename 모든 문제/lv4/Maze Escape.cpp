#include <vector>
#include <unordered_map>
#include <tuple>
#include <queue>

using namespace std;

int dist[1010][1 << 10];
unordered_map<int, int> t_idx;
vector<tuple<int, int, bool>> edges[1010];

bool is_trap(int node) {
    return t_idx.find(node) != t_idx.end();
}

bool check(int cur, int next, bool flag, int trap) {
    if (!is_trap(cur) && !is_trap(next)) return flag;
    else if (is_trap(cur) && is_trap(next)) {
        bool flag1 = trap & (1 << t_idx[cur]);
        bool flag2 = trap & (1 << t_idx[next]);

        if (!(flag1 ^ flag2)) return flag;
        else return !flag;
    }
    else if (is_trap(cur) && (trap & 1 << t_idx[cur])) return !flag;
    else if (is_trap(next) && (trap & 1 << t_idx[next])) return !flag;
    else return flag;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    fill(dist[0], dist[0] + (1010 * (1 << 10)), 1e7);

    for (int i = 0; i < traps.size(); ++i) t_idx[traps[i]] = i;
    for (auto& r : roads) {
        edges[r[0]].push_back({ r[1], r[2], true });
        edges[r[1]].push_back({ r[0], r[2], false });
    }

    priority_queue<tuple<int, int, int>> pq;

    pq.push({ 0, 0, start });
    dist[0][0] = 0;

    while (!pq.empty()) {
        auto [cost, trap, cur] = pq.top(); pq.pop();
        cost = -cost;

        if (cur == end) return cost;

        for (auto [next, time, flag] : edges[cur]) {
            if (check(cur, next, flag, trap)) {

                int newState = is_trap(next) ? trap ^ (1 << t_idx[next]) : trap;

                if (dist[next][newState] > cost + time) {
                    dist[next][newState] = cost + time;
                    pq.push({ -dist[next][newState], newState, next });
                }
            }
        }
    }

    return -1;
}