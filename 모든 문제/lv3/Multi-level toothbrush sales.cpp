#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> parent;
map<string, int> gain;

void update_gain(string now, int sell_gain) {
    if (now == "-")return;
    int delivery = sell_gain * 0.1;
    gain[now] += sell_gain - delivery;
    if (delivery == 0)return;
    update_gain(parent[now], delivery);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++) {
        parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++) {
        update_gain(seller[i], amount[i] * 100);
    }

    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(gain[enroll[i]]);
    }

    return answer;
}