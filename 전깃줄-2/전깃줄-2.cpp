#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	
	int N;
	cin >> N;

	vector<pair<int, int>> electric_wires(N);
	for (int i = 0; i < N; i++) {
		cin >> electric_wires[i].first >> electric_wires[i].second;
	}

	sort(electric_wires.begin(), electric_wires.end());

	vector<int> lis, trace(N);
	for (int i = 0; i < electric_wires.size(); i++) {
		if (lis.empty() || electric_wires[i].second > lis.back()) {
			trace[i] = lis.size();
			lis.push_back(electric_wires[i].second);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), electric_wires[i].second);
			(*it) = electric_wires[i].second;
			trace[i] = distance(lis.begin(), it);
		}
	}

	int focus = lis.size() - 1;
	deque<int> answer_queue;
	for (int i = trace.size() - 1; i >= 0; i--) {
		if (focus == trace[i]) {
			--focus;
		}
		else {
			answer_queue.push_front(electric_wires[i].first);
		}
	}

	cout << answer_queue.size() << '\n';
	for (auto it : answer_queue) {
		cout << it << '\n';
	}

	return 0;
}