#include <string>
#include <vector>
#include <map>
using namespace std;

bool CanRemove(pair<int, int> a, pair<int, int> b, vector<vector<bool>>& board)
{
    bool flag = false;
    if (a.second < b.second)
    {
        flag = true;
        for (int i = a.second + 1; i <= b.second; i++)
        {
            if (!board[a.first][i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = a.first + 1; i < b.first; i++)
            {
                if (!board[i][b.second])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        flag = true;
        for (int i = a.first + 1; i <= b.first; i++)
        {
            if (!board[i][a.second])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = a.second + 1; i < b.second; i++)
            {
                if (!board[b.first][i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        flag = true;
        for (int i = a.second - 1; i >= b.second; i--)
        {
            if (!board[a.first][i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = a.first + 1; i < b.first; i++)
            {
                if (!board[i][b.second])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        flag = true;
        for (int i = a.first + 1; i <= b.first; i++)
        {
            if (!board[i][a.second])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = a.second - 1; i > b.second; i--)
            {
                if (!board[b.first][i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        return false;
    }
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<vector<pair<int, int>>> alpha(26);
    vector<vector<bool>> realBoard(m, vector<bool>(n, false));
    map<int, string> alphaMap;
    int ansCnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                realBoard[i][j] = true;
            }
            else if (board[i][j] == '*')
            {
                continue;
            }
            else
            {
                ansCnt += 1;
                alpha[board[i][j] - 'A'].push_back(make_pair(i, j));
                alphaMap[board[i][j] - 'A'] = board[i][j];
            }
        }
    }
    ansCnt /= 2;
    bool flag2 = false;
    for (int i = 0; i < ansCnt; i++)
    {
        flag2 = false;
        for (int j = 0; j < 26; j++)
        {
            if (alpha[j].size() > 0)
            {
                if (CanRemove(alpha[j][0], alpha[j][1], realBoard))
                {
                    flag2 = true;
                    realBoard[alpha[j][0].first][alpha[j][0].second] = true;
                    realBoard[alpha[j][1].first][alpha[j][1].second] = true;
                    alpha[j] = vector<pair<int, int>>(0);
                    answer += alphaMap[j];
                    break;
                }
            }
        }
        if (!flag2)
        {
            return "IMPOSSIBLE";
        }
    }
    return answer;
}