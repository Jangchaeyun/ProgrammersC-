#include <string>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1000000000;
vector<pair<int, int>> dp;

struct compare
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

pair<int, int> ADD_PAIRS(pair<int, int>a, pair<int, int>b)
{
    return { a.first + b.first, a.second + b.second };
}

pair<int, int> DFS(int target)
{
    if (target == 0)
        return { 0, 0 };

    if (dp[target].first > 0)
        return dp[target];
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;

    if (target > 20)
    {
        int next = target <= 60 ? target % 3 : target - 60;
        q.push(ADD_PAIRS(DFS(next), { 1, 0 }));
    }

    if (target > 20 && target <= 40)
        q.push(ADD_PAIRS(DFS(target % 2), { 1, 0 }));

    if (target >= 50)
        q.push(ADD_PAIRS(DFS(target - 50), { 1, 1 }));

    int next = max(0, target - 20);
    q.push(ADD_PAIRS(DFS(next), { 1, 1 }));
    return dp[target] = q.top();
}

vector<int> solution(int target) {
    dp.resize(target + 1, { -1, -1 });
    DFS(target);
    return { dp[target].first, dp[target].second };
}