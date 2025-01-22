#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;

    sort(array.begin(), array.end());

    vector<int> numbers;

    int count = 0, max = 0, temp;
    for (int i = 0; i < array.size(); i++) {
        if (i == 0) {
            temp = array[i];
            count = 1, max = 1;
            numbers.push_back(array[i]);
        }
        else {
            if (temp == array[i]) count++;
            else {
                temp = array[i];
                count = 1;
            }
            if (max < count) {
                numbers.clear();
                numbers.push_back(array[i]);
                max = count;
            }
            else if (max == count) {
                numbers.push_back(array[i]);
            }
        }
    }
    if (numbers.size() == 1) {
        return numbers[0];
    }
    else return -1;
}