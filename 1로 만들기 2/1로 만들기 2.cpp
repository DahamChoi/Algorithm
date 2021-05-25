#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int N, answer = 0;
	cin >> N;

	vector<vector<int>> dp(N + 1, vector<int>(3));
	dp[0][0] = dp[0][1] = dp[0][2] = N;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = min(
			min((dp[i - 1][0] % 3 == 0) ? dp[i - 1][0] / 3 : INT_MAX,
				(dp[i - 1][1] % 3 == 0) ? dp[i - 1][1] / 3 : INT_MAX),
				(dp[i - 1][2] % 3 == 0) ? dp[i - 1][2] / 3 : INT_MAX);
		dp[i][1] = min(
			min((dp[i - 1][0] % 2 == 0) ? dp[i - 1][0] / 2 : INT_MAX,
				(dp[i - 1][1] % 2 == 0) ? dp[i - 1][1] / 2 : INT_MAX),
				(dp[i - 1][2] % 2 == 0) ? dp[i - 1][2] / 2 : INT_MAX);
		dp[i][2] = min(min(dp[i - 1][0] - 1, dp[i - 1][1] - 1), dp[i - 1][2]);

		if (dp[i][0] == 1 || dp[i][1] == 1 || dp[i][2] == 1) {
			answer = i;
			break;
		}
	}

	cout << answer << endl;
	int number = 1;
	vector<int> answer_list;
	for (int i = answer; i >= 0; i--) {
		answer_list.push_back(number);
		for (int j = 0; j < 3; j++) {
			if (dp[i][j] == number) {
				if (j == 0)	number *= 3;
				if (j == 1) number *= 2;
				if (j == 2) number += 1;
				break;
			}
		}
	}

	reverse(answer_list.begin(), answer_list.end());

	for (auto it : answer_list) {
		cout << it << ' ';
	}

	return 0;
}