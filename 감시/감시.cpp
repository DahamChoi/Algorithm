#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

struct cctv {
	int x, y;
	bool left_side, right_side, up_side, down_side;

	void rotate_cctv() {
		bool temp = left_side;
		left_side = down_side;
		down_side = right_side;
		right_side = up_side;
		up_side = temp;
	}
};

int get_blind_spot(vector<vector<int>>& maps, vector<cctv>& cctves) {
	int watch_area = 0;
	vector<vector<bool>> visit(maps.size(), vector<bool>(maps.front().size()));
	for (auto& it : cctves) {
		if (it.left_side) {
			for (int i = it.x - 1; i >= 0; i--) {
				if (maps[it.y][i] == 6) {
					break;
				}
				else if (maps[it.y][i] == 0 && !visit[it.y][i]) {
					visit[it.y][i] = true;
					++watch_area;
				}
			}
		}

		if (it.right_side) {
			for (int i = it.x + 1; i < maps.front().size(); i++) {
				if (maps[it.y][i] == 6) {
					break;
				}
				else if (maps[it.y][i] == 0 && !visit[it.y][i]) {
					visit[it.y][i] = true;
					++watch_area;
				}
			}
		}

		if (it.up_side) {
			for (int i = it.y - 1; i >= 0; i--) {
				if (maps[i][it.x] == 6) {
					break;
				}
				else if (maps[i][it.x] == 0 && !visit[i][it.x]) {
					visit[i][it.x] = true;
					++watch_area;
				}
			}
		}

		if (it.down_side) {
			for (int i = it.y + 1; i < maps.size(); i++) {
				if (maps[i][it.x] == 6) {
					break;
				}
				else if (maps[i][it.x] == 0 && !visit[i][it.x]) {
					visit[i][it.x] = true;
					++watch_area;
				}
			}
		}
	}

	return watch_area;
}

int answer = INT_MAX;
void func(vector<cctv>& cctves, int index, int N, int M, int wall_and_cctv_cnt, vector<vector<int>>& maps) {
	if (index >= cctves.size()) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		answer = min(answer, N * M - (wall_and_cctv_cnt + get_blind_spot(maps, cctves)));
		cctves[index].rotate_cctv();
		func(cctves, index + 1, N, M, wall_and_cctv_cnt, maps);
	}
}

int main() {
	int N, M;	cin >> N >> M;

	vector<vector<int>> maps(N, vector<int>(M));
	vector<cctv> cctves;

	map<int, vector<bool>> data = {
		{1, {false, true, false,false}},
		{2, {true, true, false , false}},
		{3, {false, true, true, false }},
		{4, {true, true, true, false}},
		{5, {true, true, true, true}}
	};

	int wall_and_cctv_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
			if (maps[i][j] != 0 && maps[i][j] != 6) {
				cctves.push_back({ j,i, data[maps[i][j]][0],data[maps[i][j]][1],data[maps[i][j]][2],data[maps[i][j]][3] });
			}

			if (maps[i][j] != 0) {
				++wall_and_cctv_cnt;
			}
		}
	}

	answer = (N * M) - wall_and_cctv_cnt;
	func(cctves, 0, N, M, wall_and_cctv_cnt, maps);
	cout << answer;

	return 0;
}
