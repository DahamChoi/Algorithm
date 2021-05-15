#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1), graph_2(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph_2[b].push_back(a);
    }

    queue<int> q;

    for (int i = 1; i < graph_2.size(); i++) {
        if (graph_2[i].empty()) {
            q.push(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!q.empty()) {
            int t = q.front();
            q.pop();

            cout << t << " ";

            for (auto it : graph[t]) {
                graph_2[it].pop_back();

                if (graph_2[it].empty()) {
                    q.push(it);
                }
            }
        }
    }
}