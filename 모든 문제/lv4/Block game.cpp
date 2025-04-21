#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool search(int y, int x, vector<vector<int>>& board)
{
    for (int i = 0; i < y; i++)
    {
        if (board[i][x] != 0)
            return false;
    }
    return true;
}

bool removeFunc(int y, int x, vector<vector<int>>& board)
{
    int ny, nx, bs = board.size();
    ny = y, nx = x;
    int num = board[y][x];
    bool flag = false;
    if (y + 1 < bs && x + 2 < bs)
    {
        if (search(y + 1, x + 1, board) && search(y + 1, x + 2, board))
        {
            if (num == board[y + 1][x] && num == board[y + 1][x + 1] && num == board[y + 1][x + 2])
            {
                board[y][x] = 0, board[y + 1][x] = 0, board[y + 1][x + 1] = 0, board[y + 1][x + 2] = 0;
                flag = true;
            }
        }
    }

    if (!flag && y + 2 < bs && x - 1 >= 0)
    {
        if (search(y + 2, x - 1, board))
        {
            if (num == board[y + 1][x] && num == board[y + 2][x] && num == board[y + 2][x - 1])
            {
                board[y][x] = 0, board[y + 1][x] = 0, board[y + 2][x] = 0, board[y + 2][x - 1] = 0;
                flag = true;
            }
        }
    }
    if (!flag && y + 2 < bs && x + 1 < bs)
    {
        if (search(y + 2, x + 1, board))
        {
            if (num == board[y + 1][x] && num == board[y + 2][x] && num == board[y + 2][x + 1])
            {
                board[y][x] = 0, board[y + 1][x] = 0, board[y + 2][x] = 0, board[y + 2][x + 1] = 0;
                flag = true;
            }
        }
    }
    if (!flag && y + 1 < bs && x - 2 >= 0)
    {
        if (search(y + 1, x - 1, board) && search(y + 1, x - 2, board))
        {
            if (num == board[y + 1][x] && num == board[y + 1][x - 1] && num == board[y + 1][x - 2])
            {
                board[y][x] = 0, board[y + 1][x] = 0, board[y + 1][x - 1] = 0, board[y + 1][x - 2] = 0;
                flag = true;
            }
        }
    }
    if (!flag && y + 1 < bs && x - 1 >= 0 && x + 1 < bs)
    {
        if (search(y + 1, x + 1, board) && search(y + 1, x - 1, board))
        {
            if (num == board[y + 1][x] && num == board[y + 1][x - 1] && num == board[y + 1][x + 1])
            {
                board[y][x] = 0, board[y + 1][x - 1] = 0, board[y + 1][x] = 0, board[y + 1][x + 1] = 0;
                flag = true;
            }
        }
    }
    if (!flag)
    {
        return false;
    }
    else
    {
        return true;
    }

}
int solution(vector<vector<int>> board) {
    int answer = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] != 0)
            {
                if (removeFunc(i, j, board))
                {
                    answer += 1;
                }
            }
            if (board[i][board.size() - j - 1] != 0)
            {
                if (removeFunc(i, board.size() - j - 1, board))
                {
                    answer += 1;
                }
            }
        }
    }

    return answer;
}