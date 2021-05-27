#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int cursor = 1;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visit, int x, int y) {
	map[y][x] = cursor;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map.size() && !visit[ny][nx] && map[ny][nx] != 0) {
			visit[ny][nx] = true;
			dfs(map, visit, nx, ny);
		}
	}
}

struct queue_info {
	int x, y, depth, continent_number;
};

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	
	int N;	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	vector<vector<bool>> visit(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j] != 0) {
				dfs(map, visit, j, i);
				++cursor;
			}
		}
	}

	int answer = INT_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) {
				visit.assign(N, vector<bool>(N));
				queue<queue_info> q;
				q.push({ j,i,0, map[i][j] });
				while (!q.empty()) {
					queue_info t = q.front();
					q.pop();

					if (map[t.y][t.x] != t.continent_number && map[t.y][t.x] != 0) {
						answer = min(answer, t.depth - 1);
						continue;
					}

					for (int i = 0; i < 4; i++) {
						int nx = t.x + dx[i];
						int ny = t.y + dy[i];
						if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map.size() && !visit[ny][nx] && map[ny][nx] != t.continent_number) {
							visit[ny][nx] = true;
							q.push({ nx, ny, t.depth + 1, t.continent_number });
						}
					}
				}
			}
		}
	}

	cout << answer;

	return 0;
}