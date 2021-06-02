#include <iostream>
#include <vector>

using namespace std;

struct rule {
	int A, B, C;
};

bool is_safe(vector<rule>& rules, int index, int D) {
	long long cnt = 0LL;
	for (auto& it : rules) {
		if (index < it.A) {
			continue;
		}

		if (index > it.B) {
			cnt += ((it.B - it.A) / it.C) + 1;
		}
		else {
			cnt += ((index - it.A) / it.C) + 1;
		}
	}

	return (cnt >= D);
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, K, D;	cin >> N >> K >> D;

	vector<rule> rules;
	for (int i = 0; i < K; i++) {
		int A, B, C;	cin >> A >> B >> C;
		rules.push_back({ A,B,C });
	}

	int left = 0, right = N, answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (is_safe(rules, mid, D)) {
			answer = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << answer;

	return 0;
}