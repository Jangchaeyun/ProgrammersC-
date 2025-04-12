#include <string>
#include <vector>
#include <queue>
#define INF 20000000

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int s)
{
    vector<int> dist(adj.size(), INF);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,s });
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            pair<int, int> node = adj[cur][i];
            if (cost + node.first < dist[node.second])
            {
                pq.push({ node.first + cost, node.second });
                dist[node.second] = cost + node.first;
            }
        }
    }

    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < fares.size(); i++)
    {
        int stt = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];
        adj[stt].push_back({ cost, end });
        adj[end].push_back({ cost, stt });
    }

    vector<int> sttRoute = dijkstra(adj, s);
    answer = sttRoute[a] + sttRoute[b]; // 처음부터 각자 가는거
    for (int i = 1; i <= n; i++)
    {
        if (i == s) continue;

        int tmp = sttRoute[i];

        vector<int> tmpArr = dijkstra(adj, i);
        tmp += tmpArr[a] + tmpArr[b];

        answer = min(answer, tmp);
    }

    return answer;
}