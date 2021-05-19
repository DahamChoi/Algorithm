#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct house {
	int r, g, b;
};

int main() {
	int n;
	cin >> n;

	vector<house> street(n);
	for (int i = 0; i < n; i++) {
		cin >> street[i].r >> street[i].g >> street[i].b;
	}

	int answer = INT_MAX;
	for (int k = 0; k < 3; k++) {
		vector<vector<int>> dp(n, vector<int>(3));

		if (k == 0) {
			dp[0][0] = 1000 * 1000 + 1;
			dp[0][1] = street.front().g;
			dp[0][2] = street.front().b;
		}
		else if (k == 1) {
			dp[0][0] = street.front().r;
			dp[0][1] = 1000 * 1000 + 1;
			dp[0][2] = street.front().b;
		}
		else {
			dp[0][0] = street.front().r;
			dp[0][1] = street.front().g;
			dp[0][2] = 1000 * 1000 + 1;
		}

		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + street[i].r;
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + street[i].g;
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + street[i].b;
		}

		answer = min(dp[n - 1][k], answer);
	}

	cout << answer;

	return 0;
}