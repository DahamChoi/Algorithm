#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m;

int main() {
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<pair<int,int>>> range_map(n, vector<pair<int, int>>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	vector<vector<bool>> visit(n, vector<bool>(m));
	int indexing = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visit[i][j]) {
				vector<pair<int, int>> q;
				vector<pair<int, int>> history;
				q.push_back({ i,j });
				visit[i][j] = true;
				int result = 0;
				while (!q.empty()) {
					pair<int, int> t = q.back();
					q.pop_back();

					++result;
					history.push_back(t);

					for (int k = 0; k < 4; k++) {
						int ny = t.first + dy[k];
						int nx = t.second + dx[k];
						if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[ny][nx] && map[ny][nx] == 0) {
							visit[ny][nx] = true;
							q.push_back({ ny,nx });
						}
					}
				}

				for (auto& it : history) {
					range_map[it.first][it.second] = { result, indexing };
				}
				++indexing;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << 0;
			}
			else {
				int answer = 0;
				vector<int> index_list;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] == 0) {
						bool is_already_check = false;
						for (int l = 0; l < index_list.size(); l++) {
							if (index_list[l] == range_map[ny][nx].second) {
								is_already_check = true;
								break;
							}
						}

						if (!is_already_check) {
							answer += range_map[ny][nx].first;
							index_list.push_back(range_map[ny][nx].second);
						}
					}
				}

				cout << (answer + 1) % 10;
			}
		}
		cout << '\n';
	}

	return 0;
}