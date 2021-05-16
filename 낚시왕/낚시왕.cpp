#include <iostream>
#include <vector>

using namespace std;

struct shark {
	int r, c, s, d, z;
	bool is_dead{ false };

	void move(int W, int H) {
		if (d == 1 || d == 2) {
			int dist = (d == 1) ? -1 : 1;
			for (int i = 0; i < s; i++) {
				if ((r <= 0 && dist == -1) || (r >= H - 1 && dist == 1)) {
					dist *= -1;
					d = (d == 1) ? 2 : 1;
				}
				r += dist;
			}
		}
		else if (d == 3 || d == 4) {
			int dist = (d == 3) ? 1 : -1;
			for (int i = 0; i < s; i++) {
				if ((c <= 0 && dist == -1) || (c >= W - 1 && dist == 1)) {
					dist *= -1;
					d = (d == 3) ? 4 : 3;
				}
				c += dist;
			}
		}
	}
};

int solution(vector<shark>& sharkes, int W, int H) {
	int answer = 0;

	for (int i = 0; i < W; i++) {
		vector<vector<shark*>> board(H, vector<shark*>(W));
		for (auto it = sharkes.begin(); it != sharkes.end(); it++) {
			if (!it->is_dead) {
				if (board[it->r][it->c] != nullptr && !board[it->r][it->c]->is_dead && board[it->r][it->c] != &(*it)) {
					if (board[it->r][it->c]->z > it->z) {
						it->is_dead = true;
					}
					else {
						board[it->r][it->c]->is_dead = true;
						board[it->r][it->c] = &(*it);
					}
				}
				else {
					board[it->r][it->c] = &(*it);
				}
			}
		}

		for (int j = 0; j < H; j++) {
			if (board[j][i] != nullptr && !board[j][i]->is_dead) {
				board[j][i]->is_dead = true;
				answer += board[j][i]->z;
				break;
			}
		}

		for (auto& it : sharkes) {
			if (!it.is_dead) {
				it.move(W, H);
			}
		}
	}

	return answer;
}

int main() {
	int R, C, M;
	cin >> R >> C >> M;

	vector<shark> sharkes;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharkes.push_back({ r - 1, c - 1, s, d, z });
	}

	cout << solution(sharkes, C, R);

	return 0;
}