#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    vector<bool> visited(1000001, false);
    vector<vector<int>> graph(1000001);

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i = 0; i < nodes.size(); i++)
    {
        if (!visited[nodes[i]]) {
            int nn = nodes[i], a;
            vector<int> v(2, 0);
            queue<int> q;
            q.push(nn);
            while (!q.empty()) {
                nn = q.front();
                q.pop();
                visited[nn] = true;
                for (int j = 0; j < graph[nn].size(); j++)
                {
                    if (!visited[graph[nn][j]])
                        q.push(graph[nn][j]);
                }
                if (nn % 2 == graph[nn].size() % 2)
                    v[0] += 1;
                else
                    v[1] += 1;
            }

            if (v[0] == 1) {
                answer[0] += 1;
            }
            if (v[1] == 1) {
                answer[1] += 1;
            }
        }

    }

    return answer;
}