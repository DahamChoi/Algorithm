#include <iostream>
#include <vector>

using namespace std;

int left_rotate(int direction) {
	return (direction - 1 < 0 ? 3 : direction - 1);
}

int back_direction(int direction) {
	return (direction == 0 ? 2 : direction == 1 ? 3 : direction == 2 ? 0 : 1);
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;		cin >> N >> M;
	int R, C, D;	cin >> R >> C >> D;
	
	vector<vector<int>> maps(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	int answer = 0, rotate_cnt = 0, index = 2;

	while (true) {
		if (maps[R][C] < 2) {
			++answer;	maps[R][C] = index++;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << maps[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;

		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int px = C + dx[i];
			int py = R + dy[i];
			if ((px >= 0 && px < M && py >= 0 && py < N && maps[py][px] == 0)) {
				++cnt;
			}
		}

		if (cnt == 0) {
			int nx = C + dx[back_direction(D)];	
			int ny = R + dy[back_direction(D)];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && maps[ny][nx] != 1) {
				C = nx;	R = ny;
				rotate_cnt = 0;
			}
			else {
				break;
			}
		}
		else {
			D = left_rotate(D);
			int	nx = C + dx[D];	
			int ny = R + dy[D];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && maps[ny][nx] == 0) {
				C = nx;	R = ny;
				rotate_cnt = 0;
			}
		}
	}

	cout << answer;

	return 0;
}