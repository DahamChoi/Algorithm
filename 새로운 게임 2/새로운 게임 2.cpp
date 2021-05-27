#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct horse {
	int x, y, direction, index;
};

int reverse_direction(int direction) {
	return ((direction == 2) ? 3 : ((direction == 3) ? 2 : ((direction == 1) ? 0 : 1)));
}

void move(vector<vector<int>>& maps, vector<vector<vector<horse*>>>& unit_map, horse& unit, int position) {
	int nx = unit.x + dx[unit.direction];
	int ny = unit.y + dy[unit.direction];
	if (nx >= 0 && nx < maps.size() && ny >= 0 && ny < maps.size()) {
		if (maps[ny][nx] == 0) {
			int ori_x = unit.x, ori_y = unit.y;
			for (int i = position; i < unit_map[ori_y][ori_x].size(); i++) {
				unit_map[ori_y][ori_x][i]->x = nx;
				unit_map[ori_y][ori_x][i]->y = ny;
			}

			unit_map[ny][nx].insert(unit_map[ny][nx].end(), unit_map[ori_y][ori_x].begin() + position, unit_map[ori_y][ori_x].end());
			unit_map[ori_y][ori_x].erase(unit_map[ori_y][ori_x].begin() + position, unit_map[ori_y][ori_x].end());
		}
		else if (maps[ny][nx] == 1) {
			int ori_x = unit.x, ori_y = unit.y;
			for (int i = position; i < unit_map[ori_y][ori_x].size(); i++) {
				unit_map[ori_y][ori_x][i]->x = nx;
				unit_map[ori_y][ori_x][i]->y = ny;
			}

			int tmp = unit_map[ny][nx].size();
			unit_map[ny][nx].insert(unit_map[ny][nx].end(), unit_map[ori_y][ori_x].begin() + position, unit_map[ori_y][ori_x].end());
			reverse(unit_map[ny][nx].begin() + tmp, unit_map[ny][nx].end());
			unit_map[ori_y][ori_x].erase(unit_map[ori_y][ori_x].begin() + position, unit_map[ori_y][ori_x].end());
		}
		else if (maps[ny][nx] == 2) {
			unit.direction = reverse_direction(unit.direction);
			nx = unit.x + dx[unit.direction];
			ny = unit.y + dy[unit.direction];
			if (nx >= 0 && nx < maps.size() && ny >= 0 && ny < maps.size() && maps[ny][nx] != 2) {
				move(maps, unit_map, unit, position);
			}
		}
	}
	else {
		unit.direction = reverse_direction(unit.direction);
		nx = unit.x + dx[unit.direction];
		ny = unit.y + dy[unit.direction];
		if (nx >= 0 && nx < maps.size() && ny >= 0 && ny < maps.size() && maps[ny][nx] != 2) {
			move(maps, unit_map, unit, position);
		}
	}
}

int main() {
	int N, K;	cin >> N >> K;

	vector<vector<int>> maps(N, vector<int>(N));
	vector<horse> horses(K);
	vector<vector<vector<horse*>>> unit_map(N, vector<vector<horse*>>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int y, x, direction;	cin >> y >> x >> direction;
		horses[i] = { x - 1, y - 1, direction - 1, i };
		unit_map[y - 1][x - 1].push_back(&horses[i]);
	}

	int answer = 0;	bool is_game_end = false;
	while (++answer < 1000 && !is_game_end) {
		for (int i = 0; i < K; i++) {
			bool is_find = false;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					auto it = find(unit_map[j][k].begin(), unit_map[j][k].end(), &horses[i]);
					if (it != unit_map[j][k].end()) {
						is_find = true;
						move(maps, unit_map, horses[i], distance(unit_map[j][k].begin(), it));
						for (int n = 0; n < N; n++) {
							for (int m = 0; m < N; m++) {
								if (unit_map[n][m].size() >= 4) {
									is_game_end = true;
									break;
								}
							}
							if (is_game_end) {
								break;
							}
						}
						break;
					}
				}
				if (is_find) {
					break;
				}
			}
		}
	}

	cout << (answer == 1000 ? -1 : (answer - 1));

	return 0;
}