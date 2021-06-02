#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct room {
	long long t, a, h;
};

bool simulation(vector<room>& dungeon, long long H_ATK, long long H_MAXHP) {
	long long H_CURHP = H_MAXHP;
	for (auto& it : dungeon) {
		if (it.t == 1) {
			long long monster_kill_time = (it.h % H_ATK == 0) ? (it.h / H_ATK) : (it.h / H_ATK + 1);
			if ((H_CURHP -= ((monster_kill_time - 1) * it.a)) <= 0) {
				return false;
			}
		}
		else if (it.t == 2) {
			H_ATK += it.a;
			H_CURHP = min(H_MAXHP, H_CURHP + it.h);
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int N, H_ATK;	cin >> N >> H_ATK;
	
	vector<room> dungeon;
	for (int i = 0; i < N; i++) {
		int t, a, h;	cin >> t >> a >> h;
		dungeon.push_back({ t,a,h });
	}

	long long left = 1, right = LLONG_MAX / 2 - 1, answer = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (simulation(dungeon, H_ATK, mid)) {
			answer = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << answer;

	return 0;
}