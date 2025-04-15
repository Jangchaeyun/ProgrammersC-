#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int idx = 1;
    for (int i = 0; i < stations.size(); i++)
    {
        int stt = stations[i] - w;
        int end = stations[i] + w;
        if (idx < stt)
        {
            int cnt = stt - idx;
            if (cnt % (w * 2 + 1) == 0) answer += cnt / (w * 2 + 1);
            else answer += cnt / (w * 2 + 1) + 1;
        }
        idx = end + 1;
    }

    if (idx <= n)
    {
        int cnt = n - idx + 1;
        if (cnt % (w * 2 + 1) == 0) answer += cnt / (w * 2 + 1);
        else answer += cnt / (w * 2 + 1) + 1;
    }

    return answer;
}