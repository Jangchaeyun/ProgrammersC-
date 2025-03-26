#include <string>
#include <vector>

using namespace std;
vector<int> answer(2, 0);

void recur(int sRow, int eRow, int sCol, int eCol, vector<vector<int>>* arr) {
	int data = (*arr)[sRow][sCol];
	bool divideable = false;
	for (int i = sRow; i < eRow && !divideable; i++) {
		for (int j = sCol; j < eCol && !divideable; j++) {
			if ((*arr)[i][j] != data) divideable = true;
		}
	}
	if (!divideable) {
		answer[data]++;
	}
	else {
		recur(sRow, (sRow + eRow) / 2, sCol, (sCol + eCol) / 2, arr);
		recur(sRow, (sRow + eRow) / 2, (sCol + eCol) / 2, eCol, arr);
		recur((sRow + eRow) / 2, eRow, sCol, (sCol + eCol) / 2, arr);
		recur((sRow + eRow) / 2, eRow, (sCol + eCol) / 2, eCol, arr);
	}
}

vector<int> solution(vector<vector<int>> arr) {
	int size = arr.size();
	recur(0, size, 0, size, &arr);
	return answer;
}