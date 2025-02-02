#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector <int> array, int n) {
	int answer = 0;

	int temp = 99999;

	sort(array.begin(), array.end());
	for (int i = 0; i < array.size(); i++)
	{
		if (abs(n - array[i]) < temp)
		{
			temp = abs(n - array[i]);
			answer = array[i];
		}
	}

	return answer;
}