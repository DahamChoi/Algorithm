#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insert_memory(vector<int>& memory, int index, int value) {
	auto it = find_if(memory.rbegin() + (memory.size() - index - 1), memory.rend(), [](int v) {
		return (v == 0);
		});

	if (it != memory.rend()) {
		*it = value;
	}
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N;	cin >> N;
	vector<pair<int,int>> pq(N);

	for (int i = 0; i < N; i++) {
		cin >> pq[i].second >> pq[i].first;
	}

	sort(pq.begin(), pq.end(), greater<>());

	vector<int> memory(N + 1);
	for (auto& it : pq) {
		insert_memory(memory, it.second, it.first);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer += memory[i];
	}

	cout << answer << '\n';

	return 0;
}