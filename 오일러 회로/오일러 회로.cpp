#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<vector<int>>& visit, vector<int>& history, int index) {
	if (history.front() == index && graph == visit) {
		for (auto& it : history) {
			cout << it + 1 << ' ';
		}
		exit(0);
	}

	for (int i = 0; i < graph[index].size(); i++) {
		if (graph[index][i] - visit[index][i] > 0) {
			history.push_back(i);
			++visit[index][i];
			++visit[i][index];
			dfs(graph, visit, history, i);
			--visit[index][i];
			--visit[i][index];
			history.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N;	cin >> N;
	vector<vector<int>> graph(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			sum += graph[i][j];
		}

		if (sum % 2 == 1) {
			cout << -1;
			return 0;
		}
	}

	vector<vector<int>> visit(N, vector<int>(N));
	vector<int> history;
	history.push_back(0);
	dfs(graph, visit, history, 0);

	cout << -1;

	return 0;
}