#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int>amswer;

    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] >= '0' && my_string[i] <= '9') {
            amswer.push_back(my_string[i] - '0');
        }
    }

    sort(amswer.begin(), amswer.end());

    return amswer;
}