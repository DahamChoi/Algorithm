#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void floyd(vector<vector<int>>& dist) {
    int n = dist.size();
    for (int iter = 0; iter < n; iter++) {
        for (int here = 0; here < n; here++) {
            for (int there = 0; there < n; there++) {
                int cost = dist[here][iter] + dist[iter][there];
                if (dist[here][there] > cost)
                    dist[here][there] = cost;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);
 
    int K, M;  cin >> K >> M;

    vector<vector<int>> graph(K, vector<int>(K, INT_MAX / 2 - 1));
    for (int i = 0; i < K; i++) {
        graph[i][i] = 1;
    }

    for (int i = 0; i < M; i++) {
        int num_1, num_2;   cin >> num_1 >> num_2;
        graph[num_1 - 1][num_2 - 1] = 1;
        graph[num_2 - 1][num_1 - 1] = 1;
    }

    floyd(graph);

    vector<int> answer;
    vector<vector<int>> group;
    vector<bool> visit(K);

    for (int i = 0; i < K; i++) {
        vector<int> group_list;
        for (int j = 0; j < K; j++) {
            if (!visit[j] && graph[i][j] != INT_MAX / 2 - 1) {
                visit[j] = true;
                group_list.push_back(j);
            }
        }

        if (!group_list.empty()) {
            group.push_back(group_list);
        }
    }

    for (auto& it : group) {
        vector<pair<int,int>> max_value_list;
        for (auto& it2 : it) {
            int max_value = 0;
            for (int i = 0; i < K; i++) {
                if (graph[it2][i] != INT_MAX / 2 - 1 && graph[it2][i] > max_value) {
                    max_value = graph[it2][i];
                }
            }

            max_value_list.push_back({ max_value, it2 });
        }

        sort(max_value_list.begin(), max_value_list.end());
        answer.push_back(max_value_list.front().second + 1);
    }

    sort(answer.begin(), answer.end());

    printf("%d\n", answer.size());
    for (auto& it : answer) {
        printf("%d\n", it);
    }

    /*
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (graph[i][j] == INT_MAX / 2 - 1) {
                cout << 0 << ' ';
            }
            else {
                cout << graph[i][j] << ' ';
            }
        }
        cout << endl;
    }
    */

	return 0;
}