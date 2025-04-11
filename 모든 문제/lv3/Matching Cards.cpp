#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> realBoard;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
vector<int> calc(pair<int, int> st, int cardN)
{
    queue<pair<int, int>> Q;
    queue<int> Cnt;
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    visited[st.first][st.second] = true;
    Q.push(st);
    Cnt.push(0);
    pair<int, int>nowP;
    int nowC, ny, nx;

    while (!Q.empty())
    {
        nowP = Q.front();
        Q.pop();
        nowC = Cnt.front();
        Cnt.pop();
        if (realBoard[nowP.first][nowP.second] == cardN)
        {
            vector<int> a(3, 0);
            a[0] = nowP.first;
            a[1] = nowP.second;
            a[2] = nowC + 1;
            realBoard[a[0]][a[1]] = 0;
            return a;
        }
        for (int i = 0; i < 4; i++)
        {
            ny = nowP.first + dy[i];
            nx = nowP.second + dx[i];
            if (ny >= 0 && ny < 4 && nx >= 0 && ny < 4 && !visited[ny][nx])
            {
                Q.push(make_pair(ny, nx));
                Cnt.push(nowC + 1);
                visited[ny][nx] = true;
            }
        }
        ny = nowP.first;
        nx = nowP.second;
        for (int i = nowP.second + 1; i < 4; i++)
        {
            if (realBoard[ny][i] != 0)
            {
                if (!visited[ny][i])
                {
                    Q.push(make_pair(ny, i));
                    Cnt.push(nowC + 1);
                    visited[ny][i] = true;
                }
                break;
            }
            if (i == 3)
            {
                if (!visited[ny][i])
                {
                    Q.push(make_pair(ny, i));
                    Cnt.push(nowC + 1);
                    visited[ny][i] = true;
                }
            }
        }
        for (int i = nowP.second - 1; i >= 0; i--)
        {
            if (realBoard[ny][i] != 0)
            {
                if (!visited[ny][i])
                {
                    Q.push(make_pair(ny, i));
                    Cnt.push(nowC + 1);
                    visited[ny][i] = true;
                }
                break;
            }
            if (i == 0)
            {
                if (!visited[ny][i])
                {
                    Q.push(make_pair(ny, i));
                    Cnt.push(nowC + 1);
                    visited[ny][i] = true;
                }
            }
        }
        for (int i = nowP.first + 1; i < 4; i++)
        {
            if (realBoard[i][nx] != 0)
            {
                if (!visited[i][nx])
                {
                    Q.push(make_pair(i, nx));
                    Cnt.push(nowC + 1);
                    visited[i][nx] = true;
                }
                break;
            }
            if (i == 3)
            {
                if (!visited[i][nx])
                {
                    Q.push(make_pair(i, nx));
                    Cnt.push(nowC + 1);
                    visited[i][nx] = true;
                }
            }
        }
        for (int i = nowP.first - 1; i >= 0; i--)
        {
            if (realBoard[i][nx] != 0)
            {
                if (!visited[i][nx])
                {
                    Q.push(make_pair(i, nx));
                    Cnt.push(nowC + 1);
                    visited[i][nx] = true;
                }
                break;
            }
            if (i == 0)
            {
                if (!visited[i][nx])
                {
                    Q.push(make_pair(i, nx));
                    Cnt.push(nowC + 1);
                    visited[i][nx] = true;
                }
            }
        }
    }
    return vector<int>(3, 0);
}
vector<vector<int>> returnComb;
vector<bool> vvc;
void combi(vector<int> comb, vector<int>pushV)
{
    if (pushV.size() == comb.size())
    {
        returnComb.push_back(pushV);
    }
    for (int i = 0; i < comb.size(); i++)
    {
        if (!vvc[i])
        {
            vector<int> newV = pushV;
            newV.push_back(comb[i]);
            vvc[i] = true;
            combi(comb, newV);
            vvc[i] = false;
        }
    }
}

int minCnt(vector<vector<int>> copyBoard, int r, int c)
{
    bool cards[9];
    fill_n(cards, 9, false);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (copyBoard[i][j] != 0)
            {
                cards[copyBoard[i][j]] = true;
            }
        }
    }
    vector<int> ccc;
    for (int i = 0; i < 9; i++)
    {
        if (cards[i])
        {
            ccc.push_back(i);
        }
    }

    realBoard = copyBoard;
    vvc = vector<bool>(ccc.size(), false);
    vector<int> ctcc;
    combi(ccc, ctcc);
    int minCnt = 16 * 16;


    for (int i = 0; i < returnComb.size(); i++)
    {
        int ty, tx, nCnt;
        vector<int> ttv;
        realBoard = copyBoard;
        nCnt = 0;
        ty = r;
        tx = c;
        for (int j = 0; j < returnComb[0].size(); j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ttv = calc(make_pair(ty, tx), returnComb[i][j]);
                ty = ttv[0];
                tx = ttv[1];
                nCnt += ttv[2];
            }
        }
        if (nCnt < minCnt)
        {
            minCnt = nCnt;
        }
    }
    return minCnt;
}

int solution(vector<vector<int>> board, int r, int c) {
    realBoard = board;
    pair<int, int> ctt;
    int answer = 0;
    answer = minCnt(board, r, c);
    return answer;
}