#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pipe {
    int x1{ 0 }, x2{ 0 }, y1{ 0 }, y2{ 0 }, direction{ 0 };
};

bool is_out_of_range(int x, int y, int n) {
    return !(y >= 0 && y < n && x >= 0 && x < n);
}

int main()
{
    int n, answer = 0;
    scanf("%d", &n);

    vector<vector<int>> map(n, vector<int>(n));
//    vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(n, vector<bool>(3)));

    vector<vector<pipe>> dist = {
        { {1, 1, 0, 0, 0}, {1, 1, 0, 1, 2} }, 
        { {0, 0, 1, 1, 1}, {0, 1, 1, 1, 2} },
        { {1, 1, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 2}}
    };

    for (int i = 0; i < n * n; i++) {
        int num = 0;
        scanf("%d", &num);
        map[i / n][i % n] = num;
    }

    queue<pipe> q;
    q.push({ 0,1,0,0,0 });
    while (!q.empty()) {
        pipe t = q.front();
        q.pop();

        if ((t.x1 == n - 1 && t.y1 == n - 1) ||
            (t.x2 == n - 1 && t.y2 == n - 1)) {
            ++answer;
            continue;
        }

        for (auto& it : dist[t.direction]) {
            int nx1 = t.x1 + it.x1;
            int nx2 = t.x2 + it.x2;
            int ny1 = t.y1 + it.y1;
            int ny2 = t.y2 + it.y2;

            if (!is_out_of_range(nx1, ny1, n) && !is_out_of_range(nx2, ny2, n) &&
                //(!visit[ny1][nx1][it.direction] || !visit[ny2][nx2][it.direction]) &&
                map[ny1][nx1] == 0 && map[ny2][nx2] == 0) {
                if (it.direction == 2 && (map[ny2][nx2 - 1] == 1 || map[ny2 - 1][nx2] == 1)) {
                    continue;
                }

//                visit[ny1][nx1][it.direction] = visit[ny2][nx2][it.direction] = true;
                q.push({ nx1, nx2, ny1, ny2, it.direction });
            }
        }
    }

    cout << answer << endl;

    return 0;
}