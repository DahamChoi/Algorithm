#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct dis_joint_set {
	vector<int> parent, size;
	dis_joint_set(int n) : parent(n), size(n, 1) {
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
		size[v] += size[u];
	}
};

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int T;	cin >> T;

	for (int i = 0; i < T; i++) {
		int index = 0;
		
		unordered_map<string, int> us;

		int F;	cin >> F;
		dis_joint_set joint(F * 2 + 1);
		for (int j = 0; j < F; j++) {
			string friend_1, friend_2;
			cin >> friend_1 >> friend_2;

			if (us.find(friend_1) == us.end()) {
				us[friend_1] = us.size();
			}

			if (us.find(friend_2) == us.end()) {
				us[friend_2] = us.size();
			}

			auto index_1 = us[friend_1];
			auto index_2 = us[friend_2];
			joint.merge(index_1, index_2);
			int result = joint.size[joint.find(index_1)];
			printf("%d\n", result);
		}
	}

	return 0;
}