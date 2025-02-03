#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;

    string a;
    string b;
    for (int i = 0; i < numbers.length(); i++)
    {
        a += numbers[i];
        if (a == "zero")
        {
            b += "0";
            a = "";
        }
        else if (a == "one")
        {
            b += "1";
            a = "";
        }
        else if (a == "two")
        {
            b += "2";
            a = "";
        }
        else if (a == "three")
        {
            b += "3";
            a = "";
        }
        else if (a == "four")
        {
            b += "4";
            a = "";
        }
        else if (a == "five")
        {
            b += "5";
            a = "";
        }
        else if (a == "six")
        {
            b += "6";
            a = "";
        }
        else if (a == "seven")
        {
            b += "7";
            a = "";
        }
        else if (a == "eight")
        {
            b += "8";
            a = "";
        }
        else if (a == "nine")
        {
            b += "9";
            a = "";
        }
    }
    answer = stoll(b);
    return answer;
}