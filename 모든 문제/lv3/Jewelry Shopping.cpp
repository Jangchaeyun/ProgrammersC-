#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0); answer[1] = INT32_MAX;
    unordered_map<string, int> us;
    for (auto& gem : gems) {
        us[gem] = 0;
    }

    int gem_num = us.size(), s = 0, cur_gems = 0;

    for (int e = 0; e < gems.size() && s <= e;) {
        if ((s != e && gems[s] == gems[e]) || us[gems[s]] > 1) {
            if (!(--us[gems[s++]])) cur_gems--;
            continue;
        }
        else if (!us[gems[e]]++) {
            cur_gems++;
        }
        if (cur_gems == gem_num) {
            if (answer[1] - answer[0] > e - s) {
                answer[0] = s + 1;
                answer[1] = e + 1;
            }
            if (!(--us[gems[s++]])) cur_gems--;
        }
        e++;
    }

    return answer;
}