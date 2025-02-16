#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int currTime = 0;
    int i = 0;
    int jobsSize = jobs.size();
    while (true) {
        if (i >= jobsSize && pq.empty()) {
            break;
        }

        while (i < jobsSize && jobs[i][0] <= currTime) {
            pq.push({ jobs[i][0], jobs[i][1] });
            i++;
        }
        if (!pq.empty()) {
            answer += (currTime - pq.top().first + pq.top().second);
            currTime += pq.top().second;
            pq.pop();
        }
        else {
            currTime = jobs[i][0];
        }
    }
    answer /= jobsSize;
    return answer;
}