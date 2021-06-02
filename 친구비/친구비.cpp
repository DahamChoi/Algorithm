#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct dis_joint_set {
	vector<int> parent;
	dis_joint_set(int n) : parent(n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);	v = find(v);
		if (u == v)	return;
		parent[u] = v;
	}
};

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M, K;	cin >> N >> M >> K;

	vector<int> money(N);
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	dis_joint_set dis_joint(N + 1);
	for (int i = 0; i < M; i++) {
		int num_1, num_2;	cin >> num_1 >> num_2;
		dis_joint.merge(num_1, num_2);
	}

	unordered_map<int, int> um;
	for (int i = 1; i < N + 1; i++) {
		int parent = dis_joint.find(i);
		if (um[parent] == 0) {
			um[parent] = money[i - 1];
		}
		else {
			um[parent] = min(um[parent], money[i - 1]);
		}
	}

	int answer = 0;
	for (auto& it : um) {
		answer += it.second;
	}

	if (answer > K) {
		cout << "Oh no";
	}
	else {
		cout << answer;
	}

	return 0;
}