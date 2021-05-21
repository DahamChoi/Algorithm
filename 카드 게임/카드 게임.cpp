#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct naive_dis_joint_set {
	vector<int> parent;
	naive_dis_joint_set(int n) {
		parent.assign(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int u) const {
		if (u == parent[u])	return u;
		return find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);	v = find(v);
		if (u != v)	parent[v] = u;
	}
};

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> cards(M);
	for (int i = 0; i < M; i++) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());

	vector<int> pay_cards(K);
	for (int i = 0; i < K; i++) {
		cin >> pay_cards[i];
	}

	naive_dis_joint_set ndjs(N + 1);
	for (int i = 0; i < pay_cards.size(); i++) {
		int s = 0, e = M - 1;
		while (s < e) {
			int mid = (s + e) / 2;
			if (pay_cards[i] >= ndjs.find(cards[mid])) {
				s = mid + 1;
			}
			else {
				e = mid;
			}
		}
		cout << ndjs.find(cards[e]) << '\n';
		ndjs.merge(e == 0 ? 0 : cards[e - 1], cards[e]);
	}

	return 0;
}