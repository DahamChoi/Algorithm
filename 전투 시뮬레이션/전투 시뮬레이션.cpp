#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct unit {
	int m, t, a, b;
};

struct order {
	int u, a, b;
};

struct queue_info {
    int x, y, cost;
};

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool is_possible(vector<vector<unit*>>& unit_map, int t, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if ((nx >= 0 && nx < unit_map.front().size() && ny >= 0 && ny < unit_map.size())
            && (!(unit_map[ny][nx] == nullptr || (unit_map[ny][nx] != nullptr && unit_map[ny][nx]->t == t)))) {
            return false;
        }
    }

    return true;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N, H, W;	cin >> N >> H >> W;
	vector<vector<int>> maps(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> maps[i][j];
		}
	}
    vector<int> costs(N);
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }

	int M;	cin >> M;
	vector<unit> units(M);
	for (int i = 0; i < M; i++) {
		cin >> units[i].m >> units[i].t >> units[i].a >> units[i].b;
	}

    vector<vector<unit*>> unit_map(H, vector<unit*>(W));
    for (int i = 0; i < M; i++) {
        unit_map[units[i].a][units[i].b] = &units[i];
    }

	int K;	cin >> K;
	vector<order> orders(K);
	for (int i = 0; i < K; i++) {
		cin >> orders[i].u >> orders[i].a >> orders[i].b;

        if (unit_map[orders[i].a][orders[i].b] == nullptr && costs[maps[orders[i].a][orders[i].b] - 1] != -1) {
            queue<queue_info> q;
            vector<vector<int>> visit(H, vector<int>(W));
            visit[units[orders[i].u - 1].a][units[orders[i].u - 1].b] = true;
            q.push({ units[orders[i].u - 1].b, units[orders[i].u - 1].a, 0 });
            bool is_safe = false;
            while (!q.empty()) {
                queue_info t = q.front();
                q.pop();

                if (t.x == orders[i].b && t.y == orders[i].a) {
                    is_safe = true;
                    break;
                }

                for (int k = 0; k < 4; k++) {
                    int nx = t.x + dx[k], ny = t.y + dy[k];
                    if (nx >= 0 && nx < W && ny >= 0 && ny < H && costs[maps[ny][nx] - 1] != -1 &&
                        (visit[ny][nx] == 0 || visit[ny][nx] > t.cost + costs[maps[ny][nx] - 1]) && t.cost + costs[maps[ny][nx] - 1] <= units[orders[i].u - 1].m &&
                        (is_possible(unit_map, units[orders[i].u - 1].t, nx, ny) || (ny == orders[i].a && nx == orders[i].b))) {
                        visit[ny][nx] = true;
                        q.push({ nx, ny, t.cost + costs[maps[ny][nx] - 1] });
                    }
                }
            }

            if (is_safe) {
                unit_map[units[orders[i].u - 1].a][units[orders[i].u - 1].b] = nullptr;
                unit_map[orders[i].a][orders[i].b] = &units[orders[i].u - 1];
                units[orders[i].u - 1].a = orders[i].a;
                units[orders[i].u - 1].b = orders[i].b;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cout << units[i].a << ' ' << units[i].b << '\n';
    }

	return 0;
}