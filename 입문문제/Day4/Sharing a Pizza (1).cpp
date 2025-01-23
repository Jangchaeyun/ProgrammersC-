#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    while (answer * 7 < n) {
        answer++;
    }
    return answer;
}