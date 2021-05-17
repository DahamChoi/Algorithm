﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solution(vector<int>& numberic) {
	set<int> lis;
	lis.insert(numberic.front());

	for (int i = 1; i < numberic.size(); i++) {
		auto it = lis.lower_bound(numberic[i]);
		if (it != lis.end()) {
			it = lis.erase(it);
		}

		lis.insert(it, numberic[i]);
	}

	cout << lis.size() << '\n';
	for (auto it = lis.begin(); it != lis.end(); it++) {
		cout << *it << " ";
	}
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> numberic(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &numberic[i]);
	}

	solution(numberic);

	return 0;
}