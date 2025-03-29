#include <string>
#include <vector>
#include <sstream>

using namespace std;

int getTime(string& s, string& e) {
	int s_time = stoi(s) * 60 + stoi(s.substr(3));
	int e_time = stoi(e) * 60 + stoi(e.substr(3));
	return e_time - s_time;
}

bool isSame(string& m, string& tmp) {
	int m_size = m.size(), tmp_size = tmp.size(), idx;
	for (int i = 0; i < m_size; i++) {
		if ((idx = m.find(tmp, i)) != -1 && m[idx + tmp_size] != '#') return true;
	}
	for (int i = 0; i < tmp_size; i++) {
		if ((idx = tmp.find(m, i)) != -1 && tmp[idx + m_size] != '#') return true;
	}
	return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int time = 0;
    for (auto infos : musicinfos) {
        istringstream iss(infos);
        vector<string> data;
        string tmp;
        while (getline(iss, tmp, ',')) {
            data.push_back(tmp);
        }
        int played_time = getTime(data[0], data[1]);
        if (played_time <= time) continue;
        int music_time = 0;
        for (auto c : data[3]) if (c != '#') music_time++;
        int tmp_time = music_time;

        while (tmp_time < played_time) {
            tmp += data[3];
            tmp_time += music_time;
        }

        while (tmp_time > played_time) {
            if (tmp.back() == '#') tmp.pop_back();
            tmp.pop_back();
            tmp_time--;
        }

        if (isSame(m, tmp)) {
            answer = data[2];
            time = played_time;
        }
    }
    return answer;
}