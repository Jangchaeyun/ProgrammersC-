#include <string>
#include <vector>

using namespace std;

int countMark(vector<string> board, char mark) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == mark) count++;
		}
	}
	return count;
}

bool playerWin(vector<string> board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

        if (board[0][i] == player && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[2][0] == player && board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return true;

    return false;
}

bool fairTurn(vector<string> board) {
    int countX = 0;
    int  countO = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') countO++;
            if (board[i][j] == 'X') countX++;
        }
    }
    if (countO - countX > 1 || countO < countX) return false;

    return true;
}

int solution(vector<string> board) {
    int cntO = countMark(board, 'O');
    int cntX = countMark(board, 'X');

    if (!fairTurn(board))
        return 0;

    if (playerWin(board, 'O') && cntO - cntX != 1)
        return 0;

    if (playerWin(board, 'X') && cntO - cntX != 0)
        return 0;

    if (playerWin(board, 'O') && playerWin(board, 'X'))
        return 0;

    return 1;
}