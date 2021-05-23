#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void turn_light(vector<vector<bool>>& map, int x, int y) {
	if (y - 1 >= 0)	map[y - 1][x] = !map[y - 1][x];
	if (y + 1 < 10) map[y + 1][x] = !map[y + 1][x];
	if (x - 1 >= 0) map[y][x - 1] = !map[y][x - 1];
	if (x + 1 < 10) map[y][x + 1] = !map[y][x + 1];
	map[y][x] = !map[y][x];
}

bool is_all_turn_off(vector<vector<bool>>& map) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	vector<vector<bool>> map(10, vector<bool>(10));

	for (int i = 0; i < 10; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O')	map[i][j] = true;
			else				map[i][j] = false;
		}
	}

	int answer = INT_MAX;
	for (int bt = 0; bt < (1 << 10); bt++) {
		vector<vector<bool>> copy_map = map;
		int cnt = 0;

		for (int i = 0; i < 10; i++) {
			if (bt & (1 << i)) {
				++cnt;
				turn_light(copy_map, i, 0);
			}
		}

		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (copy_map[i - 1][j]) {
					++cnt;
					turn_light(copy_map, j, i);
				}
			}
		}

		if (is_all_turn_off(copy_map)) {
			answer = min(answer, cnt);
		}
	}

	cout << (answer == INT_MAX ? -1 : answer);

	return 0;
}