#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void erase_door(vector<string>& map, string& key_list) {
	for (int i = 0; i < key_list.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			for (int k = 0; k < map.front().size(); k++) {
				if (tolower(map[j][k]) == key_list[i]) {
					map[j][k] = '.';
				}
			}
		}
	}
}

int solution(vector<string>& map, string& key_list) {
	int h = map.size(), w = map.front().size();
	int result = 0;

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	int loop_cnt = 0;
	while (loop_cnt++ < 100) {
		erase_door(map, key_list);
		vector<vector<bool>> visit(h, vector<bool>(w));
		queue<pair<int, int>> q;
		for (int i = 0; i < w; i++) {
			if (map[0][i] == '.' || map[0][i] == '$') {
				q.push({ i, 0 });
			}

			if (map[h - 1][i] == '.' || map[h - 1][i] == '$') {
				q.push({ i, h - 1 });
			}
		}

		for (int i = 1; i < h - 1; i++) {
			if (map[i][0] == '.' || map[i][0] == '$') {
				q.push({ 0, i });
			}

			if (map[i][w - 1] == '.' || map[i][w - 1] == '$') {
				q.push({ w - 1, i });
			}
		}

		while (!q.empty()) {
			pair<int, int> t = q.front();
			q.pop();

			if (map[t.second][t.first] == '$') {
				map[t.second][t.first] = '.';
				++result;
			}
			else if (map[t.second][t.first] >= 'a' && map[t.second][t.first] <= 'z') {
				key_list += map[t.second][t.first];
				map[t.second][t.first] = '.';
			}

			for (int i = 0; i < 4; i++) {
				int nx = t.first + dx[i];
				int ny = t.second + dy[i];
				if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visit[ny][nx] &&
					(map[ny][nx] == '.' || map[ny][nx] == '$' || (map[ny][nx] >= 'a' && map[ny][nx] <= 'z'))) {
					visit[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int t;
	cin >> t;
	
	while (t-- > 0) {
		int h, w;
		cin >> h >> w;

		vector<string> map(h);
		for (int i = 0; i < h; i++) {
			cin >> map[i];
		}

		string key_list;
		cin >> key_list;

		cout << solution(map, key_list) << '\n';
	}

	return 0;
}