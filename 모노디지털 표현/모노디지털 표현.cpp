#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);

    int K, N;   cin >> K >> N;

    unordered_map<int, int> div_list = {
        {K, 1},
        {K * 10 + K, 2},
        {K * 100 + K * 10 + K , 3},
        {K * 1000 + K * 100 + K * 10 + K, 4},
        {K * 10000 + K * 1000 + K * 100 + K * 10 + K, 5},
        {K * 100000 + K * 10000 + K * 1000 + K * 100 + K * 10 + K, 6}
    };

    for (int i = 0; i < 7; i++) {
        for (auto& it_1 : div_list) {
            if (it_1.second <= 7) {
                for (auto& it_2 : div_list) {
                    if (it_1.second + it_2.second <= 8) {
                        if ((div_list[it_1.first + it_2.first] == 0 || div_list[it_1.first + it_2.first] > it_1.second + it_2.second)) {
                            div_list[it_1.first + it_2.first] = it_1.second + it_2.second;
                        }

                        if ((div_list[it_1.first - it_2.first] == 0 || div_list[it_1.first - it_2.first] > it_1.second + it_2.second)) {
                            div_list[it_1.first - it_2.first] = it_1.second + it_2.second;
                        }

                        if ((div_list[it_1.first * it_2.first] == 0 || div_list[it_1.first * it_2.first] > it_1.second + it_2.second)) {
                            div_list[it_1.first * it_2.first] = it_1.second + it_2.second;
                        }

                        if (it_2.first != 0 && ((div_list[it_1.first / it_2.first] == 0 || div_list[it_1.first / it_2.first] > it_1.second + it_2.second))) {
                            div_list[it_1.first / it_2.first] = it_1.second + it_2.second;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int A;  cin >> A;
        int answer = div_list[A];
        if (answer == 0) {
            cout << "NO" << '\n';
        }
        else {
            cout << answer << '\n';
        }
    }

	return 0;
}