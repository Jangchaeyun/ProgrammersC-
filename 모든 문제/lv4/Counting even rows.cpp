#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int Mod = 10000000 + 19;

int solution(vector<vector<int>> a) {
    int row = a.size();
    int col = a[0].size();
    vector<vector<int>> nCr(row + 1, vector<int>(row + 1, 0));
    for (int i = 0; i <= row; i++)
    {
        nCr[i][i] = 1;
        nCr[i][0] = 1;
    }
    for (int i = 2; i <= row; i++)
    {
        for (int j = 1; j < row; j++)
        {
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % Mod;
        }
    }
    vector<long long> Cnt(col, 0);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            Cnt[j] += a[i][j];
        }
    }
    vector<vector<long long>>DP(row + 1, vector<long long>(col, 0));
    DP[Cnt[0]][0] = nCr[row][Cnt[0]];
    for (long long x = 0; x < col - 1; x++)
    {
        for (long long y = 0; y <= row; y++)
        {
            for (long long i = 0; i <= min(y, Cnt[x + 1]); i++)
            {
                long long evenChange = Cnt[x + 1] - i;
                if (row - y >= evenChange)
                {
                    DP[y - i + evenChange][x + 1] += ((DP[y][x] * nCr[y][i]) % Mod * nCr[row - y][evenChange]) % Mod;
                }
            }
        }
    }
    return DP[0][col - 1];
}