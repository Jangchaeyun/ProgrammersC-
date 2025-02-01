#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";

    for (int i = 0; i < my_string.size(); i++) {
        if (my_string.find(my_string[i]) == i)
            answer.push_back(my_string[i]);
    }
    return answer;
}