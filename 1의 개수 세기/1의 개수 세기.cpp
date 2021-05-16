#include <iostream>

using namespace std;

int main() {
	long long a, b, answer = 0;
	cin >> a >> b;
	++b;

	long long bit_cnt_1 = 0, bit_cnt_2 = 0, i = 0;
	int cnt = 1;
	while (cnt < 63) {
		i = (1LL << cnt++);
		bit_cnt_1 += (a / i) * (i / 2);
		if ((a % i) > (i / 2)) {
			bit_cnt_1 += ((a % i) - (i / 2));
		}

		bit_cnt_2 += (b / i) * (i / 2);
		if ((b % i) > (i / 2)) {
			bit_cnt_2 += ((b % i) - (i / 2));
		}
	}

	cout << bit_cnt_2 - bit_cnt_1;

	return 0;
}