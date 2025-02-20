#include <vector>
#include <string>
#include<algorithm>
using namespace std;

vector<vector<int>> minV;
vector<vector<int>> maxV;
vector<string> realArr;
vector<vector<bool>> MinCalc;
vector<vector<bool>> MaxCalc;


int DP(int st, int ed, bool isMax);

int calcDP(int st, int i, int ed, bool isMax)
{
    int a, b, c, d, rrr;
    a = DP(st, i, true);
    b = DP(st, i, false);
    c = DP(i + 1, ed, true);
    d = DP(i + 1, ed, false);
    if (isMax)
    {
        if (realArr[st * 2 - 1] == "-")
        {
            rrr = max(b - d, a + c);
        }
        else
        {
            rrr = a + c;
        }
    }
    else
    {
        if (realArr[st * 2 - 1] == "-")
        {
            rrr = min(b - c, b + d);
        }
        else
        {
            rrr = b + d;
        }
    }
    return rrr;
}

int DP(int st, int ed, bool isMax)
{
    if (isMax)
    {
        if (MaxCalc[st][ed])
        {
            return maxV[st][ed];
        }
        else
        {
            for (int i = st; i < ed; i++)
            {
                maxV[st][ed] = max(maxV[st][ed], calcDP(st, i, ed, true));

            }
            MaxCalc[st][ed] = true;
            return maxV[st][ed];
        }
    }
    else
    {
        if (MinCalc[st][ed])
        {
            return minV[st][ed];
        }
        else
        {
            for (int i = st; i < ed; i++)
            {
                minV[st][ed] = min(minV[st][ed], calcDP(st, i, ed, false));
            }
            MinCalc[st][ed] = true;
            return minV[st][ed];
        }
    }

}

int solution(vector<string> arr)
{
    int arrN = (arr.size() / 2) + 1;
    realArr = arr;
    minV = vector<vector<int>>(arrN, vector<int>(arrN, 5000000));
    maxV = vector<vector<int>>(arrN, vector<int>(arrN, -5000000));
    MinCalc = vector<vector<bool>>(arrN, vector<bool>(arrN, false));
    MaxCalc = vector<vector<bool>>(arrN, vector<bool>(arrN, false));
    for (int i = 1; i < arrN; i++)
    {
        if (arr[2 * i - 1] == "-")
        {
            MinCalc[i][i] = true;
            MaxCalc[i][i] = true;
            minV[i][i] = -stoi(arr[2 * i]);
            maxV[i][i] = -stoi(arr[2 * i]);
        }
        else
        {
            minV[i][i] = stoi(arr[2 * i]);
            MinCalc[i][i] = true;
            MaxCalc[i][i] = true;
            maxV[i][i] = stoi(arr[2 * i]);
        }
    }
    DP(1, arrN - 1, true);

    return stoi(arr[0]) + maxV[1][arrN - 1];
}