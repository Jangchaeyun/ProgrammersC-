#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<queue<int>> nodeRoad;
vector<vector<int>> nodeV;
vector<int> targetCnt;
vector<int> realTarget;
int targetLeaf()
{
    int stNode = 1;
    int nowRoad;
    while (!nodeRoad[stNode].empty())
    {
        nowRoad = nodeRoad[stNode].front();
        nodeRoad[stNode].pop();
        nodeRoad[stNode].push(nowRoad);
        stNode = nowRoad;
    }
    return stNode;
}

int canMakeLeaf()
{
    int returnInt = 0;
    for (int i = 0; i < targetCnt.size(); i++)
    {
        if (targetCnt[i] * 3 < realTarget[i])
        {
            returnInt = 1;
        }
        if (realTarget[i] < targetCnt[i])
        {
            returnInt = 2;
            return returnInt;
        }
    }
    return returnInt;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    nodeV = vector<vector<int>>(target.size() + 1);
    nodeRoad = vector<queue<int>>(target.size() + 1);
    targetCnt = vector<int>(target.size() + 1, 0);
    realTarget.push_back(0);
    realTarget.insert(realTarget.end(), target.begin(), target.end());

    for (int i = 0; i < edges.size(); i++)
    {
        nodeV[edges[i][0]].push_back(edges[i][1]);
    }
    for (int i = 0; i < nodeV.size(); i++)
    {
        sort(nodeV[i].begin(), nodeV[i].end());
    }
    for (int i = 0; i < nodeV.size(); i++) {
        for (int j = 0; j < nodeV[i].size(); j++)
        {
            nodeRoad[i].push(nodeV[i][j]);
        }
    }

    int canMake;
    int leafNum;
    vector<int> answer;
    while (true)
    {
        leafNum = targetLeaf();
        answer.push_back(leafNum);
        targetCnt[leafNum] += 1;
        canMake = canMakeLeaf();
        if (canMake == 0)
        {
            break;
        }
        else if (canMake == 2)
        {
            return vector<int>(1, -1);
        }
    }
    vector<int>RA;
    for (int i = 0; i < answer.size(); i++)
    {
        leafNum = answer[i];
        targetCnt[leafNum] -= 1;
        if (targetCnt[leafNum] * 3 >= realTarget[leafNum] - 1)
        {
            RA.push_back(1);
            realTarget[leafNum] -= 1;
        }
        else if (targetCnt[leafNum] * 3 >= realTarget[leafNum] - 2)
        {
            RA.push_back(2);
            realTarget[leafNum] -= 2;
        }
        else
        {
            RA.push_back(3);
            realTarget[leafNum] -= 3;
        }
    }

    return RA;
}