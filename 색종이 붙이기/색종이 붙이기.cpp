#include <iostream>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;

struct paper {
	int left_paper[5] = { 5,5,5,5,5 };

	int get_use_paper() {
		return (25 - (left_paper[0] + left_paper[1] + left_paper[2] + left_paper[3] + left_paper[4]));
	}
};

bool is_can_stuck_paper(vector<vector<int>>& map, int x, int y, int size) {
	if (x + size > 10 || y + size > 10) {
		return false;
	}

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}

	return true;
}

void stuck_paper(vector<vector<int>>& map, int x, int y, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			map[i][j] = 0;
		}
	}
}

void restore_paper(vector<vector<int>>& map, int x, int y, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			map[i][j] = 1;
		}
	}
}

int answer = INT_MAX;
void back_tracking(vector<vector<int>>& map, paper& item, int value, int depth) {
	if (value <= 0) {
		answer = min(answer, item.get_use_paper());
		return;
	}
	
	for (int j = 0; j < 10; j++) {
		bool is_find = false;

		for (int k = 0; k < 10; k++) {
			for (int i = 4; i >= 0; i--) {
				if (map[j][k] == 1 && item.left_paper[i] > 0 && item.get_use_paper() + 1 < answer && is_can_stuck_paper(map, k, j, i + 1)) {
					stuck_paper(map, k, j, i + 1);
					--item.left_paper[i];
					back_tracking(map, item, value - ((i + 1) * (i + 1)), depth + 1);
					restore_paper(map, k, j, i + 1);
					++item.left_paper[i];
					is_find = true;
				}
			}

			if (is_find) {
				break;
			}
		}

		if (is_find) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int value = 0;
	vector<vector<int>> map(10, vector<int>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				++value;
			}
		}
	}

	paper item;
	back_tracking(map, item, value, 0);

	cout << (answer == INT_MAX ? -1 : answer);

	return 0;
}