#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int T;	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, b;	cin >> n >> b;
		map<string, set<pair<int, int>>> um;

		for (int j = 0; j < n; j++) {
			string type, name;	int price, quality;
			cin >> type >> name >> price >> quality;
			um[type].insert({ price, quality });
		}

		int answer = 0;
		for (auto& it1 : um) {
			for (auto& it2 : it1.second) {
				int use_money = 0, select_quality = it2.second, cnt = 0;
				for (auto& it3 : um) {
					for (auto& it4 : it3.second) {
						if (it4.second >= select_quality) {
							use_money += it4.first;	++cnt;
							break;
						}
					}
				}
				
				if (use_money <= b && cnt == um.size()) {
					answer = max(answer, select_quality);
				}
			}
		}

		printf("%d\n", answer);
	}

	return 0;
}

/*
2
18 800
processor 3500_MHz 66 5
processor 4200_MHz 103 7
processor 5000_MHz 156 9
processor 6000_MHz 219 12
memory 1_GB 35 3
memory 2_GB 88 6
memory 4_GB 170 12
mainbord all_onboard 52 10
harddisk 250_GB 54 10
harddisk 500_FB 99 12
casing midi 36 10
monitor 17_inch 157 5
monitor 19_inch 175 7
monitor 20_inch 210 9
monitor 22_inch 293 12
mouse cordless_optical 18 12
mouse microsoft 30 9
keyboard office 4 10
18 800
processor 3500_MHz 66 5
processor 4200_MHz 103 7
processor 5000_MHz 156 9
processor 6000_MHz 219 12
memory 1_GB 35 3
memory 2_GB 88 6
memory 4_GB 170 12
mainbord all_onboard 52 10
harddisk 250_GB 54 10
harddisk 500_FB 99 12
casing midi 36 10
monitor 17_inch 157 5
monitor 19_inch 175 7
monitor 20_inch 210 9
monitor 22_inch 293 12
mouse cordless_optical 18 12
mouse microsoft 30 9
keyboard office 4 10
*/