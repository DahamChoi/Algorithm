#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N;	cin >> N;

	vector<pair<int, int>> peoples(N, { 0,1 });
	for (int i = 0; i < N; i++) {
		cin >> peoples[i].first;
	}

	vector<pair<int, int>> stack;
	long long answer = 0;

	int i = 0;
	while (i < N) {
		if (stack.empty()) {
			stack.push_back(peoples[i++]);
		}
		else {
			if (stack.back().first > peoples[i].first) {
				++answer;
				stack.push_back(peoples[i++]);
			}
			else if (stack.back().first == peoples[i].first) {
				peoples[i].second += stack.back().second;
				answer += stack.back().second;
				stack.pop_back();
			}
			else {
				answer += stack.back().second;
				stack.pop_back();
			}
		}
	}

	cout << answer;

	return 0;
}