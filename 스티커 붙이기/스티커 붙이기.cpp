#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<vector<int>> rotate_90_sticker(vector<vector<int>>& sticker) {
	vector<vector<int>> new_sticker(sticker.front().size(), vector<int>(sticker.size()));

	for (int i = 0; i < sticker.size(); i++) {
		for (int j = 0; j < sticker.front().size(); j++) {
			new_sticker[j][(sticker.size() - i - 1)] = sticker[i][j];
		}
	}

	return new_sticker;
}

bool is_can_stuck_sticker(vector<vector<int>>& note_book, vector<vector<int>>& sticker, int x, int y) {
	if (y + sticker.size() > note_book.size() || x + sticker.front().size() > note_book.front().size()) {
		return false;
	}

	for (int i = y; i < y + sticker.size(); i++) {
		for (int j = x; j < x + sticker.front().size(); j++) {
			if (note_book[i][j] == 1 && sticker[i - y][j - x] == 1) {
				return false;
			}
		}
	}

	return true;
}

void stuck_sticker(vector<vector<int>>& note_book, vector<vector<int>>& sticker, int x, int y) {
	for (int i = y; i < y + sticker.size(); i++) {
		for (int j = x; j < x + sticker.front().size(); j++) {
			note_book[i][j] |= sticker[i - y][j - x];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N, M, K;	cin >> N >> M >> K;

	vector<vector<int>> note_book(N, vector<int>(M));
	vector<vector<vector<int>>> stickers(K);
	for (int i = 0; i < K; i++) {
		int R, C;	cin >> R >> C;
		vector<vector<int>> sticker(R, vector<int>(C));
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> sticker[j][k];
			}
		}
		stickers[i] = sticker;
	}

	for (int i = 0; i < K; i++) {
		bool is_stuck_sticker = false;	int cnt = 0;
		while (!is_stuck_sticker && cnt++ < 4) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (is_can_stuck_sticker(note_book, stickers[i], k, j)) {
						stuck_sticker(note_book, stickers[i], k, j);
						is_stuck_sticker = true;
						break;
					}
				}
				if (is_stuck_sticker) {
					break;
				}
			}

			if (!is_stuck_sticker) {
				stickers[i] = rotate_90_sticker(stickers[i]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += (accumulate(note_book[i].begin(), note_book[i].end(), 0));
	}

	cout << answer;

	return 0;
}