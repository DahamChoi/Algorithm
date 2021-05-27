#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;

void back_tracking(vector<string>& class_room, vector<vector<bool>> visit, vector<pair<int, int>>& history, string group) {
	if (group.length() >= 7) {
		int lee_cnt = 0;
		for (int i = 0; i < group.length(); i++) {
			if (group[i] == 'S') {
				++lee_cnt;
			}
		}

		if (lee_cnt >= 4) {
			++answer;
		}

		return;
	}

	for (int i = 0; i < history.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int nx = history[i].first + dx[j];
			int ny = history[i].second + dy[j];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visit[ny][nx]) {
				visit[ny][nx] = true;
				history.push_back({ nx,ny });
				back_tracking(class_room, visit, history, group + class_room[ny][nx]);
				history.pop_back();
			}
		}
	}
}

int main() {
	vector<string> class_room(5);
	for (int i = 0; i < 5; i++) {
		cin >> class_room[i];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			vector<vector<bool>> visit(5, vector<bool>(5));
			visit[i][j] = true;
			vector<pair<int, int>> history;
			history.push_back({ j,i });
			back_tracking(class_room, visit, history, class_room[i].substr(j,1));
		}
	}

	cout << (answer / 7) << '\n';

	return 0;
}