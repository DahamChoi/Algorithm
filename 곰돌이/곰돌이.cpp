#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct queue_info {
	int x, y, depth;
};

bool simulation(vector<string>& maps, int time, int S) {
	vector<vector<string>> possibility;
	possibility.push_back(maps);

	bool is_run = false;
	while (!possibility.empty()) {
		if (time-- <= 0) {
			int first_size = possibility.size();
			for (int k = 0; k < first_size; k++) {
				queue<queue_info> q;
				int pos_x = 0, pos_y = 0;
				for (int i = 0; i < possibility[k].size(); i++) {
					for (int j = 0; j < possibility[k].front().size(); j++) {
						if (possibility[k][i][j] == 'M') {
							pos_x = j;	pos_y = i;
						}
					}
				}
				q.push({ pos_x,pos_y,0 });
				vector<vector<bool>> visit(possibility[k].size(), vector<bool>(possibility[k].size()));
				while (!q.empty()) {
					queue_info t = q.front();
					q.pop();

					if (t.depth == S) {
						if (possibility[k][t.y][t.x] == 'D') {
							return true;
						}

						possibility[k][t.y][t.x] = 'M';
						possibility[k][pos_y][pos_x] = 'G';
						possibility.push_back(possibility[k]);
						possibility[k][pos_y][pos_x] = 'M';
						possibility[k][t.y][t.x] = 'G';
						continue;
					}

					for (int l = 0; l < 4; l++) {
						int nx = t.x + dx[l], ny = t.y + dy[l];
						if (nx >= 0 && nx < possibility[k].size() && ny >= 0 && ny < possibility[k].size() &&
							possibility[k][ny][nx] != 'B' && possibility[k][ny][nx] != 'H' && possibility[k][ny][nx] != 'T' && !visit[ny][nx]) {
							visit[ny][nx] = true;
							q.push({ nx,ny,t.depth + 1 });
						}
					}
				}
			}
		}

		for (auto it = possibility.begin(); it != possibility.end(); ) {
			vector<pair<int, int>> bee_pos;
			bool is_possible = true;
			for (int i = 0; i < it->size(); i++) {
				for (int j = 0; j < it->front().size(); j++) {
					if ((*it)[i][j] == 'H' || (*it)[i][j] == 'B') {
						for (int k = 0; k < 4; k++) {
							int nx = j + dx[k], ny = i + dy[k];
							if (nx >= 0 && nx < (*it).size() && ny >= 0 && ny < (*it).size()) {
								if ((*it)[ny][nx] == 'G') {
									bee_pos.push_back({ nx,ny });
								}
								else if ((*it)[ny][nx] == 'M') {
									it = possibility.erase(it);
									is_possible = false;
									break;
								}
							}
						}
						if (!is_possible) {
							break;
						}
					}
				}
				if (!is_possible) {
					break;
				}
			}

			if (is_possible) {
				for (auto& bee : bee_pos) {
					(*it)[bee.second][bee.first] = 'B';
				}
				it++;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, S;	cin >> N >> S;
	vector<string> maps(N);
	for (int i = 0; i < N; i++) {
		cin >> maps[i];
	}

	int left = 0, right = 800, answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (simulation(maps, mid, S)) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ((answer == 0) ? -1 : answer);

	return 0;
}