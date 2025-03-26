#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long cal(long long a, long long b, char c) {
    if (c == '-') return a - b;
    else if (c == '+') return a + b;
    return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> operators;
    vector<char> oper = { '+','-','*' };
    sort(oper.begin(), oper.end());
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            tmp += expression[i];
        }
        else {
            nums.push_back(stoll(tmp));
            operators.push_back(expression[i]);
            tmp = "";
        }
    }
    nums.push_back(stoll(tmp));

    do {
        vector<long long> numsTmp(nums);
        vector<char> operTmp(operators);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < operTmp.size(); ) {
                if (oper[i] == operTmp[j]) {
                    long long res = cal(numsTmp[j], numsTmp[j + 1], operTmp[j]);
                    numsTmp.erase(numsTmp.begin() + j, numsTmp.begin() + j + 2);
                    operTmp.erase(operTmp.begin() + j);
                    numsTmp.insert(numsTmp.begin() + j, res);
                }
                else {
                    j++;
                }
            }
        }
        answer = max(answer, abs(numsTmp[0]));
    } while (next_permutation(oper.begin(), oper.end()));

    return answer;
}