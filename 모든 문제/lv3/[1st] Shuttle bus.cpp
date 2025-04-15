#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> t_time;

    for (string time : timetable) {
        string hour = time.substr(0, 2);
        string min = time.substr(3, 2);
        t_time.push_back(stoi(hour) * 60 + stoi(min));
    }

    sort(t_time.begin(), t_time.end());

    int shuttle_bus = 540;
    int idx = 0;
    int t_size = t_time.size();
    int last_time;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = idx; j < t_size; j++) {
            if (t_time[j] <= shuttle_bus) {
                idx++;
                count++;
                if (count == m) {
                    break;
                }
            }
        }

        if (i == n - 1) {
            if (count == m) {
                last_time = t_time[idx - 1] - 1;
            }
            else {
                last_time = shuttle_bus;
            }
        }

        shuttle_bus += t;
    }

    int hour = last_time / 60;
    int min = last_time % 60;

    if (hour < 10) {
        answer = "0" + to_string(hour) + ":";
    }
    else {
        answer = to_string(hour) + ":";
    }

    if (min < 10) {
        answer = answer + "0" + to_string(min);
    }
    else {
        answer = answer + to_string(min);
    }

    return answer;
}