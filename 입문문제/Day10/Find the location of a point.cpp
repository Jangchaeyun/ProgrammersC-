#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;

    int x = dot[0];
    int y = dot[1];

    if (x > 0 && y > 0) answer = 1;
    else if (x < 0 && y > 0) answer = 2;
    else if (x < 0 && y < 0) answer = 3;
    else if (x > 0 && y < 0) answer = 4;

    return answer;
}