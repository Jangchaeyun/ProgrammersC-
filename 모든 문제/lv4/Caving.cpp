#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using namespace std;

bool DFS(vector<int>& parents, vector<bool>& visited, int nowNode,
    map<int, int>& nextPrev, set<int>& nextSet, set<int>& roofSet)
{ 
    int tempNode = nowNode;
    if (roofSet.find(nowNode) != roofSet.end())
    {
        return false;
    }
    roofSet.insert(nowNode);
    queue<int> visitedQ;
    while (!visited[tempNode])
    {
        if (nextSet.find(tempNode) != nextSet.end())
        {
            bool flag = DFS(parents, visited, nextPrev[tempNode], nextPrev, nextSet, roofSet);
            if (!flag)
            {
                return flag;
            }
        }
        visitedQ.push(tempNode);
        if (tempNode == 0)
        {
            break;
        }
        tempNode = parents[tempNode];
    }
    while (!visitedQ.empty())
    {
        if (!visited[visitedQ.front()])
            visited[visitedQ.front()] = true;
        else
            break;
        visitedQ.pop();
    }
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<int>parents(n);
    vector<vector<int>> nodePath(n);
    for (int i = 0; i < path.size(); i++)
    {
        nodePath[path[i][0]].push_back(path[i][1]);
        nodePath[path[i][1]].push_back(path[i][0]);
    }

    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int nowN = q.front();
        q.pop();
        for (int i = 0; i < nodePath[nowN].size(); i++)
        {
            if (nodePath[nowN][i] != parents[nowN])
            {
                parents[nodePath[nowN][i]] = nowN;
                q.push(nodePath[nowN][i]);
            }
        }
    }
    map<int, int> nextPrev;
    set<int> nextSet;
    for (int i = 0; i < order.size(); i++)
    {
        nextPrev[order[i][1]] = order[i][0];
        nextSet.insert(order[i][1]);
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < order.size(); i++)
    {
        if (!visited[order[i][0]])
        {
            set<int>roofSet;
            bool fff = DFS(parents, visited, order[i][0], nextPrev, nextSet, roofSet);
            if (!fff)
            {
                return fff;
            }
        }
    }
    return answer;
}