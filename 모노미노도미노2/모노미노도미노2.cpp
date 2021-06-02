#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int score = 0;
void push_blue(vector<vector<int>>& blue, int type, int y) {
	int x = 0;
	while (x < 6 && blue[y][x] == 0 && (type == 2 ? blue[y + 1][x] == 0 : true)) {
		++x;
	}
	--x;

	// Push Block
	if (type == 0) {
		blue[y][x] = 1;
	}
	else if (type == 2) {
		blue[y][x] = 1;
		blue[y + 1][x] = 1;
	}
	else if (type == 1) {
		blue[y][x] = 1;
		blue[y][x - 1] = 1;
	}

	// Erase Block
	for (int i = 0; i < 6; i++) {
		bool is_clear = true;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] == 0) {
				is_clear = false;
				break;
			}
		}

		if (is_clear) {
			for (int k = i; k > 0; k--) {
				for (int j = 0; j < 4; j++) {
					blue[j][k] = blue[j][k - 1];
				}
			}

			for (int k = 0; k < 4; k++) {
				blue[k][0] = 0;
			}

			++score;
		}
	}

	// Speical Effect
	for (int k = 0; k < 2; k++) {
		bool is_speical_effect = false;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (blue[j][i] == 1) {
					is_speical_effect = true;
				}
			}
		}

		if (is_speical_effect) {
			for (int k = 5; k > 0; k--) {
				for (int j = 0; j < 4; j++) {
					blue[j][k] = blue[j][k - 1];
				}
			}

			for (int k = 0; k < 4; k++) {
				blue[k][0] = 0;
			}
		}
	}
}

void push_green(vector<vector<int>>& green, int type, int x) {
	int y = 0;
	while (y < 6 && green[y][x] == 0 && ((type == 1) ? (green[y][x + 1] == 0) : true )) {
		++y;
	}
	--y;

	// Push Block
	if (type == 0) {
		green[y][x] = 1;
	}
	else if (type == 1) {
		green[y][x] = 1;
		green[y][x + 1] = 1;
	}
	else if (type == 2) {
		green[y][x] = 1;
		green[y - 1][x] = 1;
	}

	// Erase Block
	for (int i = 0; i < 6; i++) {
		bool is_clear = true;
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 0) {
				is_clear = false;
				break;
			}
		}

		if (is_clear) {
			for (int k = i; k > 0; k--) {
				for (int j = 0; j < 4; j++) {
					green[k][j] = green[k - 1][j];
				}
			}

			for (int k = 0; k < 4; k++) {
				green[0][k] = 0;
			}

			++score;
		}
	}

	// Speical Effect
	for (int k = 0; k < 2; k++) {
		bool is_speical_effect = false;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (green[i][j] == 1) {
					is_speical_effect = true;
				}
			}
		}

		if (is_speical_effect) {
			for (int k = 5; k > 0; k--) {
				for (int j = 0; j < 4; j++) {
					green[k][j] = green[k - 1][j];
				}
			}

			for (int k = 0; k < 4; k++) {
				green[0][k] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	vector<vector<int>> blue_block(4, vector<int>(6)), green_block(6, vector<int>(4));
	for (int i = 0; i < N; i++) {
		int t, x, y;	cin >> t >> y >> x;

		push_blue(blue_block, t - 1, y);
		push_green(green_block, t - 1, x);
	}

	int blue_answer = 0, green_answer = 0;

	for (auto& it : blue_block) {
		blue_answer += accumulate(it.begin(), it.end(), 0);
	}

	for (auto& it : green_block) {
		green_answer += accumulate(it.begin(), it.end(), 0);
	}

	cout << score << '\n';
	cout << (blue_answer + green_answer) << '\n';

	return 0;
}