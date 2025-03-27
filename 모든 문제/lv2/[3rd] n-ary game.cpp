#include <string>
#include <vector>
using namespace std;

string s = "0123456789ABCDEF";

string changedNum(int n, int num) {
    string res = "";
    if (num == 0) return "0";
    while (num) {
        res = s[num % n] + res;
        num /= n;
    }
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "";

    int num = 0;
    while (str.size() <= t * m)
        str += changedNum(n, num++);
    num = p - 1;
    while (answer.size() < t) {
        answer += str[num];
        num += m;
    }
    return answer;
}