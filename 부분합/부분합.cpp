#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int main() {
	int n, s;
	scanf("%d %d", &n, &s);

	vector<int> numberic(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &numberic[i]);
	}

	int left = 0, right = 0, answer = INT_MAX, sum = 0;
	while (right < numberic.size()) {
		if (sum >= s) {
			answer = min(answer, right - left);
			sum -= numberic[left++];
		}
		else {
			sum += numberic[right++];
		}
	}

	while (sum >= s) {
		answer = min(answer, right - left);
		sum -= numberic[left++];
	}

	if (answer == INT_MAX) {
		cout << "0";
	}
	else {
		cout << answer;
	}

	return 0;
}