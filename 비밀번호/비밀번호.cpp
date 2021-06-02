#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);
//    long long N = bitset<256>("111").to_ullong();
    long long N;    cin >> N;

    bitset<256> low_bit(N), high_bit(N), original_bit(N);
    bool low_bit_find = false, high_bit_find = false;
    int last_index = 0;
    for (int i = 0; i < original_bit.size(); i++) {
        if (original_bit[i] == 1) {
            last_index = i;
        }
    }

    vector<bool> cnd(256);
    for (int i = 0; i < cnd.size(); i++) {
        cnd[i] = original_bit[cnd.size() - i - 1];
    }

    do {
        bitset<256> bit;
        for (int i = 0; i < cnd.size(); i++) {
            bit[i] = cnd[cnd.size() - i - 1];
        }

        if (bit.to_ullong() > N) {
            high_bit = bit;
            high_bit_find = true;
            break;
        }
    } while (next_permutation(cnd.begin(), cnd.end()));

    if (!high_bit_find) {
        high_bit[last_index + 1] = 1;
        high_bit[last_index] = 0;
        high_bit_find = true;
    }

    cnd.assign(256, false);

    for (int i = 0; i < cnd.size(); i++) {
        cnd[i] = original_bit[cnd.size() - i - 1];
    }

    do {
        bitset<256> bit;
        for (int i = 0; i < cnd.size(); i++) {
            bit[i] = cnd[cnd.size() - i - 1];
        }

        if (bit.to_ullong() < N) {
            low_bit = bit;
            low_bit_find = true;
            break;
        }
    } while (prev_permutation(cnd.begin(), cnd.end()));

    cout << (low_bit_find ? low_bit.to_ullong() : 0) << " " << (high_bit_find ? high_bit.to_ullong() : 0) << '\n';

    return 0;
}