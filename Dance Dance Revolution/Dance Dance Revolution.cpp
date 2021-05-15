#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_power(int prev, int next) {
	if (prev == next)	return 1;
	if (prev == 0 && next != 0)		return 2;
	if (prev == 1 && (next == 2 || next == 4))	return 3;
	if (prev == 3 && (next == 2 || next == 4))	return 3;
	if (prev == 2 && (next == 1 || next == 3))	return 3;
	if (prev == 4 && (next == 1 || next == 3))	return 3;
	if (prev == 1 && next == 3)	return 4;
	if (prev == 2 && next == 4)	return 4;
	if (prev == 3 && next == 1)	return 4;
	if (prev == 4 && next == 2)	return 4;
}


int solution(vector<int>& orders) {
	vector<vector<vector<int>>> dp(orders.size() - 1, vector<vector<int>>(5, vector<int>(5, INT_MAX / 2)));
	dp[0][orders.front()][0] = dp[0][0][orders.front()] = 2;

	for (int i = 1; i < orders.size() - 1; i++) {
		for (int j = 0; j < 5; j++) {
			if (dp[i - 1][j][orders[i - 1]] != INT_MAX / 2) {
				dp[i][orders[i]][orders[i - 1]] = min(dp[i][orders[i]][orders[i - 1]], dp[i - 1][j][orders[i - 1]] + get_power(j, orders[i]));
				dp[i][j][orders[i]] = min(dp[i][j][orders[i]], dp[i - 1][j][orders[i - 1]] + get_power(orders[i - 1], orders[i]));
			}

			if (dp[i - 1][orders[i - 1]][j] != INT_MAX / 2) {
				dp[i][orders[i - 1]][orders[i]] = min(dp[i][orders[i - 1]][orders[i]], dp[i - 1][orders[i - 1]][j] + get_power(j, orders[i]));
				dp[i][orders[i]][j] = min(dp[i][orders[i]][j], dp[i - 1][orders[i - 1]][j] + get_power(orders[i - 1], orders[i]));
			}
		}
	}

	/*
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cout << dp[i][j][k] << "\t\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	*/

	int min_power = INT_MAX;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			min_power = min(dp.back()[i][j], min_power);
		}
	}

	return min_power;
}

int main() {
	vector<int> orders;
	
	int n = 1;
	while (n != 0) {
		cin >> n;
		orders.push_back(n);
	}

	cout << solution(orders);

	return 0;
}

// 1 2 0