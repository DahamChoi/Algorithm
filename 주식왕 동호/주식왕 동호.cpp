#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int C, D, M;	cin >> C >> D >> M;

	vector<vector<int>> stocks;
	for (int i = 0; i < C; i++) {
		vector<int> stock(D);
		for (int j = 0; j < D; j++) {
			cin >> stock[j];
		}

		stocks.push_back(stock);
	}

	int left_money = M, stock_value = 0;
	for (int i = 1; i < D; i++) {
		left_money += stock_value;
		stock_value = 0;

		vector<pair<int, int>> expected_values;
		for (int j = 0; j < C; j++) {
			int distance = stocks[j][i] - stocks[j][i - 1];
			if (distance > 0 && stocks[j][i - 1] <= left_money) {
				expected_values.push_back({ distance, j });
			}
		}

		sort(expected_values.begin(), expected_values.end(), greater<>());
		
		stock_value = 0;
		for (auto& it : expected_values) {
			while (left_money - stocks[it.second][i - 1] >= 0) {
				left_money -= stocks[it.second][i - 1];
				stock_value += stocks[it.second][i];
			}
		}
	}

	cout << (left_money + stock_value);

	return 0;
}

/*
2 3 10
10 15 15
13 11 20
*/