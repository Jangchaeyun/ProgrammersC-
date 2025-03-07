#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lefthand = 10;
    int righthand = 12;

    for (int number : numbers) {
        if (number == 1 || number == 4 || number == 7) {
            answer += 'L';
            lefthand = number;
        }

        else if (number == 3 || number == 6 || number == 9) {
            answer += 'R';
            righthand = number;
        }

        else {
            if (number == 0) number = 11;

            int leftDistance = abs((lefthand - number) / 3) + abs((lefthand - number) % 3);
            int rightDistance = abs((righthand - number) / 3) + abs((righthand - number) % 3);

            if (leftDistance < rightDistance) {
                answer += 'L';
                lefthand = number;
            }
            else if (leftDistance == rightDistance) {
                if (hand == "left") {
                    answer += 'L';
                    lefthand = number;
                }
                else {
                    answer += 'R';
                    righthand = number;
                }
            }
            else {
                answer += 'R';
                righthand = number;
            }
        }
    }

    return answer;
}