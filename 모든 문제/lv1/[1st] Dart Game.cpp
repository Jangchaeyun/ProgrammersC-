#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> dart;
    vector<int> score;
    string text = "";
    int temp, score_index;

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] == '1' && dartResult[i + 1] == '0')
        {
            dart.push_back("10");
            i++;
        }
        else
        {
            text = dartResult[i];
            dart.push_back(text);
        }
    }

    for (int i = 0; i < dart.size(); i++)
    {
        score_index = score.size() - 1; 

        if (dart[i] >= "0" && dart[i] <= "9" || dart[i] == "10")
            score.push_back(stoi(dart[i]));
        else if (dart[i] == "D")
        {
            temp = pow(score[score_index], 2);
            score[score_index] = temp;
        }
        else if (dart[i] == "T")
        {
            temp = pow(score[score_index], 3);
            score[score_index] = temp;
        }
        else if (dart[i] == "*" || dart[i] == "#")
        {
            if (dart[i] == "*")
            {
                if (score.size() == 1)
                    score[score_index] *= 2;
                else
                {
                    score[score_index] *= 2;
                    score[score_index - 1] *= 2;
                }
            }
            else if (dart[i] == "#")
                score[score_index] = -score[score_index];
        }
    }

    for (int i = 0; i < score.size(); i++)
        answer += score[i];
    return answer;
}