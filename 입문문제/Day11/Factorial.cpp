#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 1;

    while (1) {
        ++answer;
        if (a * answer > n) {
            answer--;
            return answer;
        }
        else
            a *= answer;
    }
    return answer;
}