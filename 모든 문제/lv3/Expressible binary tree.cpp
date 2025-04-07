#include <string>
#include <vector>

using namespace std;


bool dfs(int64_t v, const vector<bool>& number, int32_t level) {
    if (v % 2 == 1) {

        return true;
    }

    long long pow = 1 << level;
    int left = v - pow / 2;
    int right = v + pow / 2;

    bool left_ret = dfs(left, number, level - 1);
    bool right_ret = dfs(right, number, level - 1);
    bool child = left_ret && right_ret;

    if (!child) {
        return false;
    }



    if (!number[v - 1]) {

        bool left_res = number[left - 1];
        bool right_res = number[right - 1];

        return !(left_res || right_res);

    }

    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto n : numbers) {
        long long pow = 1;
        int length = 0;
        long long root = 1;
        int level = 0;

        while (n > pow) {
            pow *= 2;
            length += 1;
        }
        while (length >= root * 2) {
            root *= 2;
            level += 1;
        }
        vector<bool> boolNum(root * 2, false);
        for (int i = 0; i <= length; i++) {
            boolNum[i] = n % 2;
            n /= 2;
        }

        answer.push_back(dfs(root, boolNum, level));
    }

    return answer;
}