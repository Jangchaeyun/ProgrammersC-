#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0;
    int count = k;
    int idx = 0;

    while (k > 0 && answer.length() < number.length() - count
        && cnt < number.length())
    {

        int maxVal = 0;
        for (int i = cnt; i < cnt + k + 1 && i < number.length(); i++) {
            if (number[i] > maxVal) {
                idx = i;
                maxVal = number[i];
            }
        }
        answer.push_back(number[idx]);

        k -= (idx - cnt);
        cnt = idx + 1;
    }

    if (k > 0) cnt = cnt + k;

    for (int i = cnt; i < number.size(); i++) answer.push_back(number[i]);

    return answer;
}