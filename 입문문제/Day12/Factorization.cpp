#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int a = 2;

    while (n != 1) {
        if (n % a == 0) {
            if (find(answer.begin(), answer.end(), a) == answer.end()) {
                answer.push_back(a);
            }
            n /= a;
        }
        else
            a++;
    }

    return answer;
}