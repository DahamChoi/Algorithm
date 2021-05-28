#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

bool is_safe(vector<int>& puzzle) {
	static vector<int> safe_puzzle = { 1,2,3,4,5,6,7,8,0 };
	return (puzzle == safe_puzzle);
}

int main() {
	vector<int> puzzle(9);
	for (int i = 0; i < 9; i++) {
		int num;	cin >> num;
		puzzle[i] = num;
	}

	map<vector<int>, int> m;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,-1,0,1 };
	int answer = INT_MAX;

	queue<pair<vector<int>,int>> q;
	q.push({ puzzle, 0 });
	while (!q.empty()) {
		pair<vector<int>, int> t = q.front();
		q.pop();

		if (is_safe(t.first) || t.second >= answer) {
			answer = min(answer, t.second);
			continue;
		}

		for (int i = 0; i < 9; i++) {
			if (t.first[i] == 0) {
				for (int j = 0; j < 4; j++) {
					int nx = (i % 3) + dx[j];
					int ny = (i / 3) + dy[j];
					if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
						t.first[i] = t.first[ny * 3 + nx];
						t.first[ny * 3 + nx] = 0;
						if (m[t.first] == 0 || m[t.first] > t.second + 1) {
							m[t.first] = t.second + 1;
							q.push({ t.first, t.second + 1 });
						}
						t.first[ny * 3 + nx] = t.first[i];
						t.first[i] = 0;
					}
				}
				break;
			}
		}
	}

	cout << (answer == INT_MAX ? -1 : answer);

	return 0;
}