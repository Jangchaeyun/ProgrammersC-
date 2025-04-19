#include <string>
#include <vector>
#include <map>
using namespace std;


long long reDP(vector<long long>& newV, vector<map<long long, long long>>& numMap, vector<long long>& DP, int nowDP);

long long calcMap(vector<map<long long, long long>>& numMap, int stIdx, vector<long long>& newV, vector<long long>& DP)
{
    long long tempIdx = stIdx;
    long long nowNum = newV[stIdx];
    long long retAns = 0;
    numMap[stIdx][nowNum] = tempIdx;
    tempIdx -= 1;
    while (true)
    {
        if (tempIdx >= 0 && numMap[tempIdx][nowNum] != 0)
        {
            tempIdx = numMap[tempIdx][nowNum];
            nowNum *= 2;
            numMap[stIdx][nowNum] = tempIdx;
            tempIdx -= 1;
            retAns += 1;
            retAns += reDP(newV, numMap, DP, tempIdx);
            retAns %= 1000000007;
        }
        else
        {
            return retAns;
        }
    }
    return retAns;
}

long long reDP(vector<long long>& newV, vector<map<long long, long long>>& numMap, vector<long long>& DP, int nowDP)
{
    if (nowDP <= 0)
    {
        return 0;
    }
    if (DP[nowDP] != 0)
    {
        return DP[nowDP];
    }
    DP[nowDP] = reDP(newV, numMap, DP, nowDP - 1);
    DP[nowDP] += calcMap(numMap, nowDP, newV, DP);
    DP[nowDP] %= 1000000007;
    return DP[nowDP];
}

vector<int> solution(vector<int> a, vector<int> s) {
    vector<int> answer(s.size(), 0);
    int pre = 0;
    for (int tc = 0; tc < s.size(); tc++)
    {
        vector<long long> newV(s[tc]);
        for (int i = 0; i < s[tc]; i++)
        {
            newV[i] = a[pre + i];
        }
        pre += s[tc];
        vector<map<long long, long long>> numMap(s[tc]);
        vector<long long> DP(s[tc], 0);
        numMap[0][newV[0]] = 1;
        answer[tc] = reDP(newV, numMap, DP, s[tc] - 1) + 1;
    }
    return answer;
}