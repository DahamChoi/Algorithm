#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> numberic(n);
	for (int i = 0; i < n; i++) {
		cin >> numberic[i];
	}

	int answer = 0, st = 0;
	vector<int> lis, trace(n);
	for (int i = 0; i < numberic.size(); i++) {
		if (lis.empty() || numberic[i] > lis.back()) {
			trace[i] = lis.size();
			lis.push_back(numberic[i]);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), numberic[i]);
			(*it) = numberic[i];
			trace[i] = distance(lis.begin(), it);
		}
	}

	int focus = lis.size() - 1;
	deque<int> answer_queue;
	for (int i = trace.size() - 1; i >= 0; i--) {
		if (focus == trace[i]) {
			--focus;
			answer_queue.push_front(numberic[i]);
		}
	}

	cout << answer_queue.size() << '\n';
	for (auto it : answer_queue) {
		cout << it << ' ';
	}

	return 0;
}