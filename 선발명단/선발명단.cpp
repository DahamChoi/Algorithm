#include <iostream>
#include <vector>

using namespace std;

long long answer = 0, value = 0;
void back_tracking(const vector<vector<int>>& status, vector<bool>& visit, int index) {
	if (index >= 11) {
		answer = max(answer, value);
		return;
	}

	for (int j = 0; j < 11; j++) {
		if (status[j][index] > 0 && !visit[j]) {
			visit[j] = true;
			value += status[j][index];
			back_tracking(status, visit, index + 1);
			value -= status[j][index];
			visit[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<vector<int>> status(11, vector<int>(11));
		vector<bool> visit(11);
		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 11; k++) {
				cin >> status[j][k];
			}
		}

		value = 0, answer = 0;
		back_tracking(status, visit, 0);
		cout << answer << '\n';
	}

	return 0;
}