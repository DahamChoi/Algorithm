#include <iostream>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool is_safe(vector<vector<int>>& map, int x, int y) {
	return (x >= 0 && x < map.front().size() && y >= 0 && y < map.size() && map[y][x] == 0);
}

bool is_done(vector<vector<int>>& map) {
	int result = 0;
	for (int i = 0; i < map.size(); i++) {
		result += accumulate(map[i].begin(), map[i].end(), 0);
	}

	return (result == (map.size() * map.front().size()));
}

int answer = INT_MAX;
void back_tracking(vector<vector<int>>& maps, int x, int y, int depth) {
	if (is_done(maps)) {
		answer = min(depth, answer);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (is_safe(maps,nx,ny)) {
			while (is_safe(maps, nx, ny)) {
				maps[ny][nx] = 1;
				nx = nx + dx[i];	ny = ny + dy[i];
			}
			nx = nx - dx[i];	ny = ny - dy[i];
			back_tracking(maps, nx, ny, depth + 1);
			int dxx = -dx[i], dyy = -dy[i];
			while (!(nx == x && ny == y)) {
				maps[ny][nx] = 0;
				nx = nx + dxx;	ny = ny + dyy;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	
	int index = 1, N, M;
	while (cin >> N >> M) {
		vector<vector<int>> maps(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			string s;	cin >> s;
			for (int j = 0; j < M; j++) {
				maps[i][j] = ((s[j] == '*'));
			}
		}

		answer = 1000000;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (maps[i][j] == 0) {
					maps[i][j] = 1;
					back_tracking(maps, j, i, 0);
					maps[i][j] = 0;
				}
			}
		}

		cout << "Case " << (index++) << ": " << (answer == 1000000 ? -1 : answer) << '\n';
	}
	
	return 0;
}