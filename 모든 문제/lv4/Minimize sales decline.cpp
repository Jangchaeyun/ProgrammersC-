#include <string>
#include <vector>

#define MAX 300010

using namespace std;

int DP[MAX][2];
vector<int> Node[MAX];
vector<int> Cost;

int Min(int A, int B) { return A < B ? A : B; };

void Make_Relation(vector<int> sales, vector<vector<int>> links)
{
	for (int i = 0; i < links.size(); i++)
	{
		int Parent = links[i][0];
		int Child = links[i][1];
		Node[Parent].push_back(Child);
	}
}

void DFS(int Cur) {
	bool Leaf_Node = true;
	for (int i = 0; i < Node[Cur].size(); i++)
	{
		int Next = Node[Cur][i];
		Leaf_Node = false;
		DFS(Next);
	}
	
	if (Leaf_Node == true)
	{
		DP[Cur][0] = 0;
		DP[Cur][1] = Cost[Cur - 1];
		return;
	}

	int Sum = 0;
	int Min_Cost = 987654321;
	bool Attend = true;
	for (int i = 0; i < Node[Cur].size(); i++)
	{
		int Child = Node[Cur][i];
		Sum += Min(DP[Child][0], DP[Child][1]);
		if (DP[Child][0] >= DP[Child][1])Attend = false;
		Min_Cost = Min(Min_Cost, DP[Child][1] - DP[Child][0]);
	}

	DP[Cur][1] = Cost[Cur - 1] + Sum;
	if (Attend == false) DP[Cur][0] = Sum;
	else DP[Cur][0] = Sum + Min_Cost;
}

int solution(vector<int> sales, vector<vector<int>> links) {
	int answer = 0;
	Cost = sales;
	Make_Relation(sales, links);
	DFS(1);
	answer = Min(DP[1][0], DP[1][1]);
	return answer;
}