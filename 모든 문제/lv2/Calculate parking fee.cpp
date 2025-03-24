#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int calculate(vector<int> fees, int gap)
{
    if (gap <= fees[0]) return fees[1];
    float tmp = (gap - fees[0]) / (float)fees[2];
    return fees[1] + ceil(tmp) * fees[3];
}

int timeGap(vector<string> time)
{
    vector<int> timeToMinute;
    for (int i = 0; i < time.size(); i++)
    {
        string hour = "";
        string minute = "";
        stringstream stream(time[i]);
        getline(stream, hour, ':');
        getline(stream, minute, ':');
        timeToMinute.push_back(stoi(hour) * 60 + stoi(minute));
    }

    int total = 0;
    for (int i = 0; i < timeToMinute.size(); i += 2)
    {
        total += timeToMinute[i + 1] - timeToMinute[i];
    }
    return total;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    stringstream stream;
    map<string, vector<string>> m;
    for (int i = 0; i < records.size(); i++)
    {
        string car;
        string time;
        stream.str(records[i]);
        stream >> time >> car;
        m[car].push_back(time);
    }

    for (auto u : m)
    {
        if (u.second.size() % 2 == 1) u.second.push_back("23:59");
        int gap = timeGap(u.second);
        answer.push_back(calculate(fees, gap));
    }

    return answer;
}