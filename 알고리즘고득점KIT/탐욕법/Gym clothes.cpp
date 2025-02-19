#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    for (int i = 0; i < reserve.size(); i++) {
        auto lostIter = find(lost.begin(), lost.end(), reserve[i]);
        if (lostIter != lost.end()) {
            reserve.erase(reserve.begin() + i);
            lost.erase(lostIter); 
            i--;
        }
    }

    int lostN = lost.size();
    answer += n - lostN;

    int turn = 0;
    while (turn < 2) {
        for (int i = 0; i < lostN; i++) {
            auto left = find(reserve.begin(), reserve.end(), lost[i] - 1);
            auto right = find(reserve.begin(), reserve.end(), lost[i] + 1);
            if (left == reserve.end() && right == reserve.end()) {
                continue;
            }
            if (turn == 0 && left != reserve.end() && right != reserve.end()) {
                continue;
            }
            else if (left != reserve.end()) {
                reserve.erase(left);
                answer++;
            }
            else {
                reserve.erase(right);
                answer++;
            }
        }
        turn++;
    }

    return answer;
}