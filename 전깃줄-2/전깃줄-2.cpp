#include <iostream>
#include <vector>
#include <algorithm>

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

	int max_length = 0;

	vector<int> lis, trace;
	for (int i = 0; i < electric_wires.size(); i++) {
		if (lis.empty() || electric_wires[i].second > lis.back()) {
			lis.push_back(electric_wires[i].second);
			trace.push_back(electric_wires[i].second);
		}
		else {
			auto it = upper_bound(lis.begin(), lis.end(), electric_wires[i].second);
			(*it) = electric_wires[i].second;
		}
	}

	cout << electric_wires.size() - lis.size() << '\n';
	for (int i = 0; i < electric_wires.size(); i++) {
		auto it = find(lis.begin(), lis.end(), electric_wires[i].second);
		if (it == lis.end()) {
			cout << electric_wires[i].first << '\n';
		}
	}

	return 0;
}