#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct dis_joint_set {
	vector<int> parent, owner;
	dis_joint_set(int n) : parent(n), owner(n) {
		for (int i = 0; i < n; i++) {
			owner[i] = parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	int find_owner(int u) {
		if (u == owner[u])	return u;
		return find_owner(owner[u]);
	}

	void merge(int u, int v) {
		if (find_owner(u) == v) {
			owner[u] = u;
		}	
		owner[v] = u;

		u = find(u);	v = find(v);
		if (u == v)		return;
		parent[u] = v;
	}
};

vector<string> split_string(string s, string delimiter) {
	vector<string> result;

	auto pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		string token = s.substr(0, pos);
		result.push_back(token);
		s.erase(0, pos + delimiter.length());
	}

	if (!s.empty()) {
		result.push_back(s);
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;	cin >> N >> M;

	map<string, int> um;
	vector<string> v;

	dis_joint_set joint_set(N);
	for (int i = 0; i < N; i++) {
		string s;	cin >> s >> s >> s;
		um[s] = i;
		v.push_back(s);
	}

	for (int i = 0; i < M; i++) {
		string s;	cin >> s >> s >> s;
		s = split_string(s, ",").front();
		string ss;	cin >> ss >> ss;
		vector<string> split_list = split_string(ss, ",");

		if (atoi(split_list.back().c_str()) == 1) {
			joint_set.merge(um[s], um[split_list.front()]);
		}
		else {
			joint_set.merge(um[split_list.front()], um[s]);
		}
	}

	set<int> s;
	int cnt = 0;
	for (auto& it : um) {
		s.insert(joint_set.find_owner(it.second));
	}

	cout << s.size() << '\n';
	for (auto& it : s) {
		cout << "Kingdom of " << v[it] << '\n';
	}

	return 0;
}