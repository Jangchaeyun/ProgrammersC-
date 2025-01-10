#include <string>
#include <cctype>

using namespace std;

string solution(const string myString) {
    string answer = myString;
    for (size_t i = 0; i < answer.length(); i++) {
        answer[i] = tolower(answer[i]);
    }
    return answer;
}