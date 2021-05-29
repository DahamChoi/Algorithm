#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, L;	cin >> N >> L;
	vector<vector<int>> maps(N, vector<int>(N));
	vector<vector<int>> runway(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (maps[i][j] - maps[i][j + 1] == 1) {
				if (j + L < N) {
					bool is_can_build_runway = true;
					for (int k = j + 1; k <= j + L; k++) {
						if (maps[i][j + 1] != maps[i][k]) {
							is_can_build_runway = false;
							break;
						}
					}

					if (is_can_build_runway) {
						for (int k = j + 1; k <= j + L; k++) {
							++runway[i][k];
						}
					}
				}
			}
		}

		for (int j = N - 1; j > 0; j--) {
			if (maps[i][j] - maps[i][j - 1] == 1) {
				if (j - L >= 0) {
					bool is_can_build_runway = true;
					for (int k = j - 1; k >= j - L; k--) {
						if (maps[i][j - 1] != maps[i][k]) {
							is_can_build_runway = false;
							break;
						}
					}

					if (is_can_build_runway) {
						for (int k = j - 1; k >= j - L; k--) {
							++runway[i][k];
						}
					}
				}
			}
		}

		bool is_safe = true;
		for (int j = 0; j < N - 1; j++) {
			int dist = maps[i][j] - maps[i][j + 1];
			if (!(dist == 0 || (dist < 0 ? runway[i][j] == 1 : runway[i][j + 1] == 1)) || runway[i][j] > 1) {
				is_safe = false;
				break;
			}
		}

		if (is_safe) {
			++answer;
		}
	}

	runway.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (maps[j][i] - maps[j + 1][i] == 1) {
				if (j + L < N) {
					bool is_can_build_run_way = true;
					for (int k = j + 1; k <= j + L; k++) {
						if (maps[j + 1][i] != maps[k][i]) {
							is_can_build_run_way = false;
							break;
						}
					}

					if (is_can_build_run_way) {
						for (int k = j + 1; k <= j + L; k++) {
							++runway[k][i];
						}
					}
				}
			}
		}

		for (int j = N - 1; j > 0; j--) {
			if (maps[j][i] - maps[j - 1][i] == 1) {
				if (j - L >= 0) {
					bool is_can_build_run_way = true;
					for (int k = j - 1; k >= j - L; k--) {
						if (maps[j - 1][i] != maps[k][i]) {
							is_can_build_run_way = false;
							break;
						}
					}

					if (is_can_build_run_way) {
						for (int k = j - 1; k >= j - L; k--) {
							++runway[k][i];
						}
					}
				}
			}
		}

		bool is_safe = true;
		for (int j = 0; j < N - 1; j++) {
			int dist = maps[j][i] - maps[j + 1][i];
			if (!(dist == 0 || (dist < 0 ? runway[j][i] == 1 : runway[j + 1][i] == 1)) || runway[j][i] > 1) {
				is_safe = false;
				break;
			}
		}

		if (is_safe) {
			++answer;
		}
	}

	cout << answer;

	return 0;
}