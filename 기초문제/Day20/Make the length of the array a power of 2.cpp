#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> arr) {
    int new_length = 1;
    while (new_length < arr.size()) {
        new_length *= 2;
    }

    vector<int> answer = arr;

    while (answer.size() < new_length) {
        answer.push_back(0);
    }

    return answer;
}