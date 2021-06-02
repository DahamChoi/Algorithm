#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct queue_info {
	int id, w, k, time;
};

struct compare {
	bool operator()(const queue_info& left, const queue_info& right) {
		return (left.time == right.time) ? (left.k < right.k) : (left.time > right.time);
	}
};

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, k;	cin >> N >> k;

	vector<pair<int, int>> customers(N);
	priority_queue<queue_info, vector<queue_info>, compare> pq;
	for (int i = 0; i < N; i++) {
		cin >> customers[i].first >> customers[i].second;
	}

	int index = 0;
	for (int i = 0; i < k && i < N; i++) {
		pq.push({customers[index].first, customers[index].second, i + 1, customers[index].second});
		++index;
	}

	long long answer = 0, multi_value = 1;
	int time = 0;
	while (!pq.empty()) {
		queue_info t = pq.top();
		pq.pop();

		answer += ((multi_value++) * t.id);

		vector<queue_info> vtop;
		vtop.push_back(t);

		while (!pq.empty() && pq.top().time == t.time) {
			vtop.push_back(pq.top());
			answer += ((multi_value++) * vtop.back().id);
			pq.pop();
		}

		sort(vtop.begin(), vtop.end(), [](const queue_info& left, const queue_info& right) {
			return left.k < right.k;
			});

		for (auto& it : vtop) {
			if (index < N) {
				pq.push({ customers[index].first, customers[index].second, it.k, it.time + customers[index].second });
				++index;
			}
		}
	}

	cout << answer;

	return 0;
}