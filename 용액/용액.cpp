#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> acides, alkalies;

	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		if (w > 0) {
			acides.push_back(w);
		}
		else {
			alkalies.push_back(w);
		}
	}

	if (acides.empty()) {
		sort(alkalies.begin(), alkalies.end(), greater<>());
		cout << alkalies[1] << " " << alkalies.front();
		return 0;
	}

	if (alkalies.empty()) {
		sort(acides.begin(), acides.end());
		cout << acides.front() << " " << acides[1];
		return 0;
	}

	sort(acides.begin(), acides.end());
	sort(alkalies.begin(), alkalies.end());

	int acide = acides.front(), alkalie = alkalies.back(), min_value = INT_MAX;
	for (int i = 0; i < acides.size(); i++) {
		auto it = upper_bound(alkalies.begin(), alkalies.end(), -acides[i]);
		if (it != alkalies.begin()) {
			int value_1 = abs(*(it - 1) + acides[i]);
			if (value_1 < min_value) {
				acide = acides[i];
				alkalie = *(it - 1);
				min_value = value_1;
			}
		}
		
		if (it != alkalies.end()) {
			int value_2 = abs(*it + acides[i]);
			if (value_2 < min_value) {
				acide = acides[i];
				alkalie = *(it);
				min_value = value_2;
			}
		}
	}

	if (acides.size() > 2 && min_value != INT_MAX && min_value > acides.front() + acides[1]) {
		cout << acides.front() << " " << acides[1];
		return 0;
	}

	if (alkalies.size() > 2 && min_value != INT_MAX && min_value > abs(alkalies.back() + alkalies[alkalies.size() - 2])) {
		cout << alkalies[alkalies.size() - 2] << " " << alkalies.back();
		return 0;
	}

	cout << alkalie << " " << acide << endl;

	return 0;
}
