#include <string>
#include <cctype>

using namespace std;

string solution(const string myString) {
    string answer = myString;
    for (size_t i = 0; i < answer.length(); i++) {
        if (islower(answer[i])) {
            answer[i] = toupper(answer[i]);
        }
    }
    return answer;
}
