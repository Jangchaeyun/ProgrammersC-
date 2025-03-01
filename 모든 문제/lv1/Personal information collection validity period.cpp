#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int year, month, day, total;
map<char, int> t_map;
vector<int> priv;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    year = stoi(today.substr(0, 4)); month = stoi(today.substr(5, 2)); day = stoi(today.substr(8, 2));
    total = year * 12 * 28 + (month - 1) * 28 + day;

    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char alpha; int month;
        ss >> alpha >> month;
        t_map[alpha] = month;
    }

    for (int i = 0; i < privacies.size(); i++) {
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        char a = privacies[i].back();
        int tmp = y * 12 * 28 + (m - 1) * 28 + d + (t_map[a] * 28 - 1);

        priv.push_back(tmp);
    }

    for (int i = 0; i < priv.size(); i++) {
        if (priv[i] < total) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}