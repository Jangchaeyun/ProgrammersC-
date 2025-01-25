#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";

    for (int j = 0; j < my_string.size(); j++) {
        for (int i = 0; i < n; i++) {
            answer += my_string[j];
        }
    }

    return answer;
}