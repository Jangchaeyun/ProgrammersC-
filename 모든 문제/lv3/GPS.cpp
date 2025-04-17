#include <vector>
using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> DP(k + 1, vector<int>(n + 1, 101));
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        graph[i].push_back(i);
    }
    for (int i = 0; i < edge_list.size(); i++)
    {
        graph[edge_list[i][0]].push_back(edge_list[i][1]);
        graph[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    DP[0][gps_log[0]] = 0;
    for (int t = 0; t < k - 1; t++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (DP[t][i] != 101)
            {
                for (int j = 0; j < graph[i].size(); j++)
                { //다음 원소
                    if (DP[t + 1][graph[i][j]] >= DP[t][i] + 1)
                    {
                        if (gps_log[t + 1] != graph[i][j])
                        {
                            DP[t + 1][graph[i][j]] = DP[t][i] + 1;
                        }
                        else
                        {
                            DP[t + 1][graph[i][j]] = DP[t][i];
                        }
                    }
                }
            }
        }
    }
    if (DP[k - 1][gps_log[k - 1]] == 101)
    {
        DP[k - 1][gps_log[k - 1]] = -1;
    }
    return DP[k - 1][gps_log[k - 1]];
}