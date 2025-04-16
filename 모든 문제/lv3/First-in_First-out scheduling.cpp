#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int st = 0, ed = cores[0] * ((n / cores.size()) + 1), mid;
    int Work = 0, fW = 0;
    while (st <= ed)
    {
        mid = (st + ed) / 2;
        Work = 0;
        for (int i = 0; i < cores.size(); i++)
        {
            Work += (mid / cores[i]) + 1;
        }
        if (Work >= n)
        {
            ed = mid - 1;
            fW = Work;
        }
        else
        {
            st = mid + 1;
        }
    }
    for (int i = cores.size() - 1; i >= 0; i--)
    {
        if (st % cores[i] == 0)
        {
            if (fW == n)
            {
                return i + 1;
            }
            fW -= 1;
        }
    }
    return answer;
}