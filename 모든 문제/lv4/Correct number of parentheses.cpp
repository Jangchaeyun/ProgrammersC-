#include <string>
#include <vector>

using namespace std;

int Answer;

void DFS(int Open, int Close, int Cnt, int Total)
{
	if (Open > Total / 2 || Close > Total / 1) return;
	if (Close > Open) return;
	if (Cnt == Total)
	{
		Answer++;
		return;
	}

	DFS(Open + 1, Close, Cnt + 1, Total);
	DFS(Open, Close + 1, Cnt + 1, Total);
}

int solution(int n)
{
	DFS(0, 0, 0, n * 2);
	return Answer;
}