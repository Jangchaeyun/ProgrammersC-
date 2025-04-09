#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> node[50001];
int dist[50001] = { 0, };
bool isTop[50001] = { false, };
vector<int> ans(2); 

void dijkstra(vector<int> gates) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (auto it : gates) {
        q.push({ 0,it });
        dist[it] = 0;
    }

    while (!q.empty()) {
        int x = q.top().second;
        int cost = q.top().first;
        q.pop();
        if (ans[0] != -1 && ans[1] < cost) continue;
        if (isTop[x]) {
            if (ans[0] == -1 || ans[1] > cost) {
                ans[0] = x;
                ans[1] = cost;
            }
            else if (ans[1] == cost && ans[0] > x) ans[0] = x;
            continue;
        }

        for (int i = 0; i < node[x].size(); i++) {
            int next = node[x][i][0];
            int nCost = node[x][i][1];
            nCost = max(nCost, cost);

            if (dist[next] == -1 || nCost < dist[next]) {
                dist[next] = nCost;
                q.push({ nCost,next });
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (auto it : summits) isTop[it] = true;
    fill(dist, dist + 50001, -1); // dist 배열을 -1로 초기화
    ans[0] = -1;
    ans[1] = -1;

    for (int i = 0; i < paths.size(); i++) {
        int n1 = paths[i][0];
        int n2 = paths[i][1];
        int cost = paths[i][2];

        node[n1].push_back({ n2,cost });
        node[n2].push_back({ n1,cost });
    }
    dijkstra(gates);
    return ans;
}