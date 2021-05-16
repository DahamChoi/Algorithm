#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>>& graph, vector<vector<int>>& back_graph) {
	vector<int> answer;

	queue<int> q;
	for (int i = 1; i < back_graph.size(); i++) {
		if (back_graph[i].empty()) {
			q.push(i);
		}
	}

	for (int i = 0; i < graph.size(); i++) {
		if (!q.empty()) {
			int t = q.front();
			q.pop();

			answer.push_back(t);

			for (auto it : graph[t]) {
				auto ers = find(back_graph[it].begin(), back_graph[it].end(), t);
				if (ers != back_graph[it].end()) {
					back_graph[it].erase(ers);
				}

				if (back_graph[it].empty()) {
					q.push(it);
				}
			}
		}
	}

	return answer;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1), back_graph(n + 1);

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		vector<int> sub_pd_list;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			sub_pd_list.push_back(b);
		}

		for (int j = 0; j < sub_pd_list.size() - 1; j++) {
			graph[sub_pd_list[j]].push_back(sub_pd_list[j + 1]);
			back_graph[sub_pd_list[j + 1]].push_back(sub_pd_list[j]);
		}
	}

	vector<int> answer = solution(graph, back_graph);
	if (answer.size() != n) {
		cout << "0";
	}
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << '\n';
		}
	}

	return 0;
}

/*

6 3
3 1 4 3
4 6 2 5 4
2 3 2

*/