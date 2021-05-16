#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> graph, dp(16, vector<int>(1 << 16, -1));
static const int IMPOSSIBLE = INT_MAX / 2 - 1;

int solution(int current, int visited) {
	if (visited == (1 << graph.size()) - 1) {
		return graph[current][0] ? graph[current][0] : IMPOSSIBLE;
	}

	int& ret = dp[current][visited];
	if (ret != -1) {
		return ret;
	}

	ret = IMPOSSIBLE;

	for (int i = 0; i < graph.size(); i++) {
		if (visited & (1 << i))	continue;
		if (graph[current][i] == 0)	continue;
		ret = min(ret, solution(i, visited | (1 << i)) + graph[current][i]);
	}

	return ret;
}

int main(){
	int n;
	cin >> n;

	graph = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	cout << solution(0, 1);

	return 0;
}