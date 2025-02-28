#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "";
	
	int idxA = 0;
	int idxB = 0;
	for (int i = 0; i < goal.size(); i++) {
		if (cards1[idxA] == goal[i])
		{
			idxA++;
		}
		else if (cards2[idxB] == goal[i])
		{
			idxB++;
		}
		else
		{
			return "No";
		}
	}
	return "Yes";
}