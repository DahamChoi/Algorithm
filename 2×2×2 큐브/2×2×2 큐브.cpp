#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool is_safe(vector<int>& cube) {
    for (int i = 0; i < 6; i++) {
        if (!(cube[i * 4] == cube[i * 4 + 1] && cube[i * 4 + 1] == cube[i * 4 + 2] && cube[i * 4 + 2] == cube[i * 4 + 3])) {
            return false;
        }
    }

    return true;
}

bool move_rail(vector<int> cube, int rail_number, int cnt) {
    static vector<vector<int>> rail = {
        {1,3,5,7,9,11,24,22},
        {2,4,6,8,10,12,23,21},
        {13,14,5,6,17,18,21,22},
        {15,16,7,8,19,20,23,24},
        {3,4,17,19,10,9,16,14},
        {1,2,18,20,12,11,16,14}
    };

    for (int i = 0; i < cnt; i++) {
        int front_number = cube[rail[rail_number].front() - 1];
        for (int j = 0; j < 7; j++) {
            cube[rail[rail_number][j] - 1] = cube[rail[rail_number][j + 1] - 1];
        }
        cube[rail[rail_number].back() - 1] = front_number;
    }

    return is_safe(cube);
}

int main() {
    vector<int> cube(24);

    for (int i = 0; i < 24; i++) {
        cin >> cube[i];
    }

    bool answer = false;
    for (int i = 0; i < 6; i++) {
        answer |= move_rail(cube, i, 2);
        answer |= move_rail(cube, i, 6);
    }

    cout << (answer ? 1 : 0) << '\n';

    return 0;
}