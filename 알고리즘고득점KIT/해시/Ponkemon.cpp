#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
	int n = nums.size();
	map<int, int> m;
	for (int i = 0; i < n; i++) m[nums[i]]++;
	return min((int)m.size(), n / 2);
}