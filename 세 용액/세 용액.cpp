#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> waters;

	for (int i = 0; i < n; i++) {
		long long w;
		cin >> w;
		waters.push_back(w);
	}

	sort(waters.begin(), waters.end());

	long long min_value = LLONG_MAX;
	vector<long long> answer;
	for (int i = 0; i < waters.size(); i++) {
		for (int j = waters.size() - 1; j >= i + 1; j--) {
			auto it = upper_bound(waters.begin() + i, waters.begin() + j + 1, -(waters[i] + waters[j]));
			if (it != waters.begin() && (it - 1) != (waters.begin() + i) && (it - 1) != (waters.begin() + j)) {
				long long value_1 = abs(*(it - 1) + waters[i] + waters[j]);
				if (value_1 < min_value) {
					min_value = value_1;
					answer = { waters[i], waters[j], *(it - 1) };
				}
			}

			if (it != waters.end() && it != (waters.begin() + j) && it != (waters.begin() + i)) {
				long long value_2 = abs(*it + waters[i] + waters[j]);
				if (value_2 < min_value) {
					min_value = value_2;
					answer = { waters[i], waters[j], *it };
				}
			}
		}
	}

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}
