#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string s1, s2;
    int num;
    cin >> s1 >> s2;
    cin >> num;
    vector<string> movement(num);
    for (int i = 0; i < movement.size(); i++) {
        cin >> movement[i];
    }

    map<string, pair<int, int>> movement_map =
    { {"R", {1,0}},{"L", {-1,0}},{"B", {0,-1}},{"T", {0,1}},{"RT", {1,1}},{"LT", {-1,1}},{"RB", {1,-1}},{"LB", {-1,-1}} };

    pair<int, int> king_pos = { s1[0] - 'A', s1[1] - '0' - 1 };
    pair<int, int> stone_pos = { s2[0] - 'A', s2[1] - '0' - 1 };
    for (int i = 0; i < movement.size(); i++) {
        pair<int, int> next_king_pos = {
            king_pos.first + movement_map[movement[i]].first,
            king_pos.second + movement_map[movement[i]].second
        };

        pair<int, int> next_stone_pos = {
            stone_pos.first + movement_map[movement[i]].first,
            stone_pos.second + movement_map[movement[i]].second
        };

        if (next_king_pos.first >= 0 && next_king_pos.first < 8 && next_king_pos.second >= 0 && next_king_pos.second < 8 &&
            next_stone_pos.first >= 0 && next_stone_pos.first < 8 && next_stone_pos.second >= 0 && next_stone_pos.second < 8) {
            king_pos = next_king_pos;
            stone_pos = next_stone_pos;
        }
    }

    printf("%c%d\n", king_pos.first + 'A', king_pos.second + 1);
    printf("%c%d", stone_pos.first + 'A', stone_pos.second + 1);
}