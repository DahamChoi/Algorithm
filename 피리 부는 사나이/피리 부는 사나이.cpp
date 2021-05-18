#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int solution(vector<string>& map) {
    vector<vector<bool>> visit(n, vector<bool>(m));
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) {
                queue<pair<int, int>> q;
                q.push({ j,i });

                ++answer;
                while (!q.empty()) {
                    pair<int, int> t = q.front();
                    q.pop();

                    visit[t.second][t.first] = true;
                    if (t.first - 1 >= 0 && !visit[t.second][t.first - 1] && map[t.second][t.first - 1] == 'R') {
                        q.push({ t.first - 1, t.second });
                    }

                    if (t.first + 1 < m && !visit[t.second][t.first + 1] && map[t.second][t.first + 1] == 'L') {
                        q.push({ t.first + 1, t.second });
                    }

                    if (t.second - 1 >= 0 && !visit[t.second - 1][t.first] && map[t.second - 1][t.first] == 'D') {
                        q.push({ t.first, t.second - 1 });
                    }

                    if (t.second + 1 < n && !visit[t.second + 1][t.first] && map[t.second + 1][t.first] == 'U') {
                        q.push({ t.first, t.second + 1 });
                    }

                    if (map[t.second][t.first] == 'R' && !visit[t.second][t.first + 1]) {
                        q.push({ t.first + 1, t.second });
                    }
                    else if (map[t.second][t.first] == 'L' && !visit[t.second][t.first - 1]) {
                        q.push({ t.first - 1, t.second });
                    }
                    else if (map[t.second][t.first] == 'D' && !visit[t.second + 1][t.first]) {
                        q.push({ t.first, t.second + 1 });
                    }
                    else if (map[t.second][t.first] == 'U' && !visit[t.second - 1][t.first]) {
                        q.push({ t.first, t.second - 1 });
                    }
                }
            }
        }
    }

    return answer;
}

int main() {
    cin >> n >> m;

    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    cout << solution(map);

    return 0;
}

/*
3 3
RDL
RDL
RUL
*/