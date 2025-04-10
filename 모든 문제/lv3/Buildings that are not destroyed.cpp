#include <string>
#include <vector>
using namespace std;

int cusum[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size(), m = board[0].size();

    for (auto sk : skill) {
        int degree = sk[5];
        if (sk[0] == 1) degree = -degree;
        cusum[sk[1]][sk[2]] += degree;
        cusum[sk[3] + 1][sk[4] + 1] += degree;
        cusum[sk[1]][sk[4] + 1] -= degree;
        cusum[sk[3] + 1][sk[2]] -= degree;
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            cusum[i][j + 1] += cusum[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cusum[i + 1][j] += cusum[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] + cusum[i][j] > 0) answer++;
        }
    }

    return answer;
}