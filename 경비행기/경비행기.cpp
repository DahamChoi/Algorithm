#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

struct queue_info {
    int depth, index;
};

bool test_fly(vector<pair<int,int>>& airfileds, int oil_tank, int k) {
    vector<bool> visit(airfileds.size());

    queue<queue_info> q;
    q.push({ 0, static_cast<int>(airfileds.size() - 2) });
    visit[airfileds.size() - 2] = true;

    while (!q.empty()) {
        queue_info t = q.front();
        q.pop();

        if (t.index == airfileds.size() - 1) {
            return true;
        }

        for (int i = 0; i < airfileds.size(); i++) {
            int need_oil = (ceil(
                sqrt(
                    pow(static_cast<double>(airfileds[i].first - airfileds[t.index].first), 2) +
                    pow(static_cast<double>(airfileds[i].second - airfileds[t.index].second), 2)
                )
            ));

            if (!visit[i] && need_oil / 10.0 <= oil_tank && t.depth <= k) {
                visit[i] = true;
                q.push({ t.depth + 1, i });
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);
    int n, k;   cin >> n >> k;

    vector<pair<int, int>> airfileds(n);
    for (int i = 0; i < n; i++) {
        cin >> airfileds[i].first >> airfileds[i].second;
    }
    airfileds.push_back({ 0, 0 });
    airfileds.push_back({ 10000, 10000 });
  
    int answer = 0;
    int left = 1, right = 1500;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (test_fly(airfileds, mid, k)) {
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}