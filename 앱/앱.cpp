#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<int>& memory, vector<int>& cost, int m) {
    int answer = INT_MAX, n = memory.size();

    vector<vector<int>> dp(n + 1, vector<int>(10001));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (cost[i - 1] <= j) {
                dp[i][j] = max(memory[i - 1] + dp[i - 1][j - cost[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }

            if (dp[i][j] >= m) {
                answer = min(answer, j);
            }
        }
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> memory(n), cost(n);
    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cout << solution(memory, cost, m);

    return 0;
}

/*
100 10000000
30 10 20 35 40 10 10 10 10 10 30 10 20 35 40 10 10 10 10 10 30 10 20 35 40 10 10 10 10 10 30 10 20 35 40 10 10 10 10 10
3 0 3 5 4 5 4 3 2 1 3 0 3 5 4 5 4 3 2 1 3 0 3 5 4 5 4 3 2 1 3 0 3 5 4 5 4 3 2 1
*/