#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<int> tree[250001];
queue<int> lastNode;

int BFS(int n)
{
    int visited[250001] = { 0, };
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    int cnt = -1;
    while (!q.empty())
    {
        cnt++;
        int qSize = q.size();
        lastNode = q;
        for (int i = 0; i < qSize; i++)
        {
            int curVal = q.front();
            q.pop();
            visited[curVal] = 1;
            for (int val : tree[curVal])
            {
                if (visited[val] == 0)
                {
                    q.push(val);
                    visited[val] = 1;
                }
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edges) {
    int leafNode = 1;

    for (vector<int> v : edges)
    {
        tree[v[0]].push_back(v[1]);
        tree[v[1]].push_back(v[0]);
    }

    BFS(1);

    int dist = BFS(lastNode.front());
    if (lastNode.size() > 1)
        return dist;

    dist = BFS(lastNode.front());
    if (lastNode.size() > 1)
        return dist;

    return dist - 1;
}