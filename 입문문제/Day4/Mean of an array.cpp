#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;

    answer = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();

    return answer;
}