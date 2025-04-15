#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int START = 0;
const int END = 1;

int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<int>> times;

    for (int i = 0; i < lines.size(); i++) {
        int hour = stoi(lines[i].substr(11, 2)) * 60 * 60;
        int minute = stoi(lines[i].substr(14, 2)) * 60;
        double second = stod(lines[i].substr(17, 6));

        int end = (hour + minute + second) * 1000;
        int ms = stod(lines[i].substr(24, 5)) * 1000;
        int start = end - ms + 1;
        times.push_back({ start, START });
        times.push_back({ end + 999, END });
    }

    sort(times.begin(), times.end());

    int count = 0;
    for (const auto& time : times) {
        if (time[1] == START) {
            count++;
        }
        else {
            count--;
        }
        answer = max(count, answer);
    }

    return answer;
}
