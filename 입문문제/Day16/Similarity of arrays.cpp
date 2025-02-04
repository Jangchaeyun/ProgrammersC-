#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    set<string> s3(s1.begin(), s1.end());
    for (int i = 0; i < s2.size(); i++)
    {
        if (s3.find(s2[i]) != s3.end())
        {
            answer++;
        }
    }


    return answer;
}