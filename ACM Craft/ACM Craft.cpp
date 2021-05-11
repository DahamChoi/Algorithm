#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
int answer = 0;
void dfs(vector<vector<int>>& graph, vector<int>& cost, vector<int>& dp, int index) {
	if (graph[index].empty()) {
		answer = dp[index] + cost[index];
	}
	else {
		for (int i = 0; i < graph[index].size(); i++) {
			if (dp[index] + cost[index] > dp[graph[index][i]]) {
				dp[graph[index][i]] = dp[index] + cost[index];
				dfs(graph, cost, dp, graph[index][i]);
			}
		}
	}
}
*/

int solution(vector<vector<int>>& graph, vector<int>& cost, vector<int>& dp, int w) {
//	dfs(graph, cost, dp, w);
	int answer = 0;

	queue<int> q;
	q.push(w);
	while (!q.empty()) {
		int t = q.front();
		q.pop();

		if (graph[t].empty()) {
			answer = max(answer, dp[t] + cost[t]);
		}
		else {
			for (int i = 0; i < graph[t].size(); i++) {
				if (dp[t] + cost[t] > dp[graph[t][i]]) {
					dp[graph[t][i]] = dp[t] + cost[t];
					q.push(graph[t][i]);
				}
			}
		}
	}

	return answer;
}

int main(){
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int n, k, w;
		scanf("%d %d", &n, &k);

		vector<int> cost(n + 1);
		vector<vector<int>> graph(n + 1);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &cost[j]);
		}

		for (int j = 0; j < k; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			graph[y].push_back(x);
		}

		scanf("%d", &w);

		vector<int> dp(n + 1);
		cout << solution(graph, cost, dp, w) << endl;
	}

	return 0;
}