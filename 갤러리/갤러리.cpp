#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> gallery(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		string s;	cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'X') {
				gallery[i][j] = true;
			}
			else {
				gallery[i][j] = false;
			}
		}
	}

	int answer = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (!gallery[i][j] && !gallery[i][j + 1] && gallery[i - 1][j] && gallery[i - 1][j + 1]) {
				++answer;	++j;
			}
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (!gallery[i][j] && !gallery[i][j + 1] && gallery[i + 1][j] && gallery[i + 1][j + 1]) {
				++answer;	++j;
			}
		}
	}

	for (int i = 1; i < M - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (!gallery[j][i] && !gallery[j + 1][i] && gallery[j][i - 1] && gallery[j + 1][i - 1]) {
				++answer;	++j;
			}
		}
	}

	for (int i = 1; i < M - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (!gallery[j][i] && !gallery[j + 1][i] && gallery[j][i + 1] && gallery[j + 1][i + 1]) {
				++answer;	++j;
			}
		}
	}

	cout << answer;

	return 0;
}