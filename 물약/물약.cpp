#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

long long get_cost_material(
	vector<pair<string, vector<pair<string, long long>>>>& recipes, 
	unordered_map<string, long long>& materials,
	vector<pair<string, long long>>& recipe, int depth) {
	long long answer = 0;
	for (auto& it : recipe) {
		if (materials[it.first] == 0) {
			return LLONG_MAX;
		}
		else {
			answer = min(1000000001LL, answer + (materials[it.first] * it.second));
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<string, long long> materials;
	for (int i = 0; i < N; i++) {
		string s;	int n;
		cin >> s >> n;
		materials[s] = n;
	}

	vector<pair<string, vector<pair<string, long long>>>> recipes;
	for (int i = 0; i < M; i++) {
		string title, s;
		vector<pair<string, long long>> recipe;
		cin >> s;
		s.push_back('+');

		auto pos = distance(s.begin(), find(s.begin(), s.end(), '=')) + 1;
		title = s.substr(0, pos - 1);
		auto it = s.begin();
		while ((it = find(s.begin() + pos, s.end(), '+')) != s.end()) {
			int n = atoi(s.substr(pos, 1).c_str()), dist = distance(s.begin(), it);
			string name = s.substr(pos + 1, dist - pos - 1);
			recipe.push_back({ name,n });
			pos = dist + 1;
		}

		recipes.push_back({ title, recipe });
	}

	while (M-- > 0) {
		for (auto& it : recipes) {
			long long cost = get_cost_material(recipes, materials, it.second, 0);
			materials[it.first] = (cost != LLONG_MAX) ? ((materials[it.first] == 0) ? cost : min(materials[it.first], cost)) : materials[it.first];
		}
	}

	long long answer = materials["LOVE"];
	cout << (answer == 0 ? -1 : min(1000000001LL, answer));

	return 0;
}