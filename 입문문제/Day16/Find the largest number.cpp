#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
	vector<int> answer;

	int max_num = 0;
	int max_index = 0;

	for (int i = 0; i < array.size(); i++)
	{
		if (max_num < array[i])
		{
			max_num = array[i];
			max_index = i;
		}
	}

	answer.push_back(max_num);
	answer.push_back(max_index);

	return answer;
}