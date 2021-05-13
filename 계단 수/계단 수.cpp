#include <iostream>
#include <vector>

using namespace std;

static const int DIVISION_NUMBER = 1000000000;
long long dp[101][10][1 << 10];

long long solution(int n) {
    long long answer = 0;

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < (1 << 10); k++) {
                dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] +
                    ((0 < j ? dp[i - 1][j - 1][k] : 0) + 
                    (j < 9 ? dp[i - 1][j + 1][k] : 0)) % DIVISION_NUMBER) % DIVISION_NUMBER;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        answer = (answer + dp[n][i][(1 << 10) - 1]) % DIVISION_NUMBER;
    }

    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n);

    return 0;
}