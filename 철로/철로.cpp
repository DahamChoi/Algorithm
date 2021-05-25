#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> ho(n);
	for (int i = 0; i < n; i++) {
		cin >> ho[i].first >> ho[i].second;
		if (ho[i].first > ho[i].second) {
			int temp = ho[i].first;
			ho[i].first = ho[i].second;
			ho[i].second = temp;
		}
	}

	int d;
	cin >> d;

	int trail_st = 0, trail_ed = 0, answer = 0;
	for (int i = ho.size() - 1; i >= 0; i--) {
		trail_st = ho[i].first;		trail_ed = trail_st + d;

		int result = 0;
		for (int j = i; j < ho.size(); j++) {
			if (trail_st <= ho[j].first && trail_ed >= ho[j].second) {
				++result;
			}
		}

		answer = max(result, answer);
	}

	cout << answer << '\n';

	return 0;
}