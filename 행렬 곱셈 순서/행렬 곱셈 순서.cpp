#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>>& dp, vector<pair<int,int>>& matrixes, int s, int e) {
    if (s == e) {
        return 0;
    }

    if (dp[s][e] > 0) {
        return dp[s][e];
    }

    if (s + 1 == e) {
        return matrixes[s].first * matrixes[s].second * matrixes[e].second;
    }

    for (int i = s; i < e; i++) {
        int value = 
            solution(dp, matrixes, s, i) +
            solution(dp, matrixes, i + 1, e) +
            matrixes[s].first * matrixes[i].second * matrixes[e].second;
        dp[s][e] = (dp[s][e] == 0) ? value : min(dp[s][e], value);
    }

    return dp[s][e];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<pair<int, int>> matrixes(n);

    for (int i = 0; i < n; i++) {
        cin >> matrixes[i].first >> matrixes[i].second;
    }

    cout << solution(dp, matrixes, 0, n - 1);

    return 0;
}