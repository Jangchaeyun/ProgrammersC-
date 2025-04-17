#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end(), [](vector<int> a, vector<int>b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
    int upV, downV, tempUp, tempDown;
    for (int i = 0; i < data.size(); i++)
    {
        upV = pow(2, 31) - 1, downV = 0;
        tempUp = upV, tempDown = downV;
        for (int j = i + 1; j < data.size(); j++)
        {
            if (data[j - 1][0] != data[j][0])
            {
                upV = tempUp;
                downV = tempDown;
            }
            if (data[j][1] == data[i][1] || data[i][0] == data[j][0])
            {
                continue;
            }
            else if (data[j][1] > data[i][1])
            {
                if (upV >= data[j][1])
                {
                    answer += 1;
                }
                tempUp = min(tempUp, data[j][1]);
            }
            else if (data[j][1] < data[i][1])
            {
                if (downV <= data[j][1])
                {
                    answer += 1;
                }
                tempDown = max(tempDown, data[j][1]);
            }
        }
    }
    return answer;
}