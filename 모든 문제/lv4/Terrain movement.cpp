#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
vector<vector<int>> realLand;
vector<vector<int>> landCost;
vector<int> landC;
vector<vector<pair<int, int>>> flu;
int ry, rx;
void BFS(int h, int stY, int stX, int landNum)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(stY, stX));
    landCost[stY][stX] = landNum;
    int ny, nx, y, x, CT;
    while (!Q.empty())
    {
        y = Q.front().first;
        x = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= 0 && ny < ry && nx >= 0 && nx < rx)
            {
                CT = abs(realLand[ny][nx] - realLand[y][x]);
                if (CT <= h && landCost[ny][nx] != landNum)
                {
                    landCost[ny][nx] = landNum;
                    Q.push(make_pair(ny, nx));
                }
            }
        }
    }
    return;
}

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int>b) {
        return a.first > b.first;
    }
};

vector<int> visited;
int landCalc(int landNum)
{
    int y, x, ny, nx, CT, minCT, minLandNum;
    vector<int>canV;
    canV.push_back(1);
    visited[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    minLandNum = 1;
    while (canV.size() < landNum)
    {
        minCT = 10001;
        for (int i = 0; i < flu[minLandNum].size(); i++)
        {
            y = flu[minLandNum][i].first;
            x = flu[minLandNum][i].second;
            for (int j = 0; j < 4; j++)
            {
                ny = y + dy[j];
                nx = x + dx[j];
                if (ny >= 0 && ny < ry && nx >= 0 && nx < rx && visited[landCost[ny][nx]] == -1)
                {
                    CT = abs(realLand[ny][nx] - realLand[y][x]);
                    pq.push(make_pair(CT, landCost[ny][nx]));
                }
            }
        }
        while (true)
        {
            if (visited[pq.top().second] == -1)
            {
                minLandNum = pq.top().second;
                minCT = pq.top().first;
                visited[minLandNum] = minCT;
                pq.pop();
                break;
            }
            else
            {
                pq.pop();
            }
        }
        canV.push_back(minLandNum);
    }
    int ans = 0;
    for (int i = 1; i < visited.size(); i++)
    {
        ans += visited[i];
    }
    return ans;
}

int solution(vector<vector<int>> land, int height) {
    realLand = land;
    ry = land.size();
    rx = land[0].size();
    landCost = vector<vector<int>>(ry, vector<int>(rx, 0));
    int lNum = 0;
    for (int i = 0; i < ry; i++)
    {
        for (int j = 0; j < rx; j++)
        {
            if (landCost[i][j] == 0)
            {
                lNum += 1;
                BFS(height, i, j, lNum);
            }
        }
    }
    landC = vector<int>(lNum + 1, 10001);
    flu = vector<vector<pair<int, int>>>(lNum + 1);
    visited = vector<int>(lNum + 1, -1);
    for (int i = 0; i < ry; i++)
    {
        for (int j = 0; j < rx; j++)
        {
            flu[landCost[i][j]].push_back(make_pair(i, j));
        }
    }
    return landCalc(lNum);
}