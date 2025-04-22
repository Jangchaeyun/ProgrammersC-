#include<vector>
#include<map>
#include<algorithm>
using namespace std;

long long solution(vector<vector<int> > land, int P, int Q) {
    map<long long, long long> PM;
    int n = land.size();
    vector<long long>mV(n * n);
    int ss = 0;
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            mV[ss] = land[i][j];
            ss++;
        }
    }
    sort(mV.begin(), mV.end(), [](long long a, long long b) {return a > b; });
    long long stMax = mV[0];
    long long retAns = 0, minV, nowBlock = 0;
    for (int i = 0; i < n * n; i++)
    {
        retAns += (stMax - mV[i]) * P;
        if (mV[i] == stMax)
        {
            nowBlock++;
        }
    }
    minV = retAns;
    long long block = n * n;
    for (int i = nowBlock; i < mV.size(); i++)
    {
        if (mV[i] == stMax)
        {
            nowBlock += 1;
        }
        else
        {
            retAns += (stMax - mV[i]) * (Q * (nowBlock)-P * (block - nowBlock));
            stMax = mV[i];
            minV = min(minV, retAns);
            nowBlock += 1;
        }
    }
    return minV;
}