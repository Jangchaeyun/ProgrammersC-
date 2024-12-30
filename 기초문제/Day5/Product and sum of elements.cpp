#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int product = 1;
    int sum = 0;
    for (int num : num_list) {
        product *= num;
        sum += num;
    }
    int sum_square = sum * sum;
    if (product < sum_square)
        answer = 1;
    else
        answer = 0;

    return answer;
}