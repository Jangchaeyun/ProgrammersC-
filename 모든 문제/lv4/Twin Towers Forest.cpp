#include <iostream>
#include <vector>
#define MOD 1000000007

int solution(int n, int count) {
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, 0));

    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] * (i - 1) * 2 + dp[i - 1][j - 1]) % MOD;
        }
    }

    return static_cast<int>(dp[n][count]);
}

int main() {
    int n, count;
    std::cin >> n >> count;
    std::cout << solution(n, count) << std::endl;
    return 0;
}
