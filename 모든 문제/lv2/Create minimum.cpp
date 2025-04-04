#include <vector>
#include <algorithm>

using namespace std;

bool Cmp(int A, int B)
{
	if (A > B) return true;
	return false;
}

int solution(vector<int> A, vector<int> B)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), Cmp);
	int Sum = 0;
	for (int i = 0; i < A.size(); i++)
	{
		int Value = A[i] * B[i];
		Sum = Sum + Value;
	}
	return Sum;
}