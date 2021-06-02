#include <iostream>
#include <vector>
#include <map>

using namespace std;

void rotate_90(vector<int>& cube, int start) {
    vector<int> tmp = cube;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube[start + ((j * 3) + (3 - i - 1))] = tmp[start + (i * 3 + j)];
        }
    }
}

void move_rail(vector<int>& cube, int rail_number, int cnt) {
    static vector<vector<int>> rail = {
        {1,4,7,10,13,16,19,22,25,54,51,48},
        {3,6,9,12,15,18,21,24,27,52,49,46},
        {28,29,30,10,11,12,37,38,39,46,47,48},
        {34,35,36,16,17,18,43,44,45,52,53,54},
        {7,8,9,37,40,43,21,20,19,36,33,30},
        {1,2,3,39,42,45,27,26,25,34,31,28}
    };

    for (int i = 0; i < cnt; i++) {
        int front_number = cube[rail[rail_number].front() - 1];
        for (int j = 0; j < rail.front().size() - 1; j++) {
            cube[rail[rail_number][j] - 1] = cube[rail[rail_number][j + 1] - 1];
        }
        cube[rail[rail_number].back() - 1] = front_number;
    }
}

struct order_info {
    int rotate_cnt, rotate_index, rail_number, rail_cnt;
};

int main() {
    map<string, order_info> m = {
        {"U+",{1,0,2,3}},{"U-",{3,0,2,9}},{"D+",{1,2,3,9}},{"D-",{3,2,3,3}},{"F+",{1,1,4,9}},{"F-",{3,1,4,3}},
        {"B+",{1,5,5,3}},{"B-",{3,5,5,9}},{"L+",{1,3,0,9}},{"L-",{3,3,0,3}},{"R+",{1,4,1,3}},{"R-",{3,4,1,9}}
    };

    map<int, char> colors = {
        {0,'w'},{1,'r'},{2,'y'},{3,'g'},{4,'b'},{5,'o'}
    };

    ios::sync_with_stdio(false);	cin.tie(NULL);
    int T;  cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> cube(54);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                cube[i * 9 + j] = i;
            }
        }

        int n;  cin >> n;
        for (int j = 0; j < n; j++) {
            string s;   cin >> s;
            order_info info = m[s];

            for (int k = 0; k < info.rotate_cnt; k++) {
                rotate_90(cube, info.rotate_index * 9);
            }
            move_rail(cube, info.rail_number, info.rail_cnt);
        }

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << colors[cube[(j * 3 + k)]];
            }
            cout << '\n';
        }
    }

	return 0;
}