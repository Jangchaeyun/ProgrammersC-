#include <string>
#include <vector>

using namespace std;

int solution(string b) {
    int answer = 0;
    int a, bc;
    char op;

    int s = b.find(' ');
    a = stoi(b.substr(0, s));
    op = b[s + 1];
    bc = stoi(b.substr(s + 3));

    if (op == '*') return a * bc;
    else if (op == '+') return a + bc;
    else return a - bc;
    return answer;
}