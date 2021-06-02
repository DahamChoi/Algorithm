#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void erase_material(const vector<vector<int>>& maps, vector<int>& primary_material, const pair<int,int>& pos) {
    pair<int, int> dist[6] = { {0,-2},{1,-1},{1,1},{0,2},{-1,-1},{-1,1} };
    for (int k = 0; k < 6; k++) {
        pair<int, int> npos = { pos.first + dist[k].first, pos.second + dist[k].second };
        auto it = find(primary_material.begin(), primary_material.end(), maps[npos.second][npos.first]);
        if (it != primary_material.end()) {
            primary_material.erase(it);
        }
    }
}

void erase_material_2(const vector<int>& material_cnt, vector<int>& primiary_material) {
    int min_value = INT_MAX;
    for (int i = 1; i < material_cnt.size(); i++) {
        if (find(primiary_material.begin(), primiary_material.end(), i) != primiary_material.end()) {
            min_value = min(material_cnt[i], min_value);
        }
    }

    for (auto it = primiary_material.begin(); it != primiary_material.end(); ) {
        if (min_value != material_cnt[*it]) {
            it = primiary_material.erase(it);
        }
        else {
            it++;
        }
    }
}

int main() {
    static const int MAP_SIZE = 5000;
    static const int ANSWER_SIZE = 10000;
    vector<vector<int>> maps(MAP_SIZE, vector<int>(MAP_SIZE));
    pair<int, int> pos = { MAP_SIZE / 2, MAP_SIZE / 2 };
  
    pair<int, int> direction[6] = { {1,-1},{0,-2},{-1,-1},{-1,1},{0,2},{1,1} };
    int direction_index = 0, cnt = 0, add_cnt = 1;
    vector<int> material_cnt(6), answer(ANSWER_SIZE);

    material_cnt[1] = answer.front() = maps[pos.second][pos.first] = 1;
    for (int i = 1; i < ANSWER_SIZE; i++) {
        pos.first += direction[direction_index].first;
        pos.second += direction[direction_index].second;

        vector<int> primary_material = { 1,2,3,4,5 };
        erase_material(maps, primary_material, pos);
        if (primary_material.size() > 1) {
            erase_material_2(material_cnt, primary_material);
        }

        answer[i] = maps[pos.second][pos.first] = primary_material.front();
        ++material_cnt[primary_material.front()];

        if (++cnt >= ((direction_index == 1) ? add_cnt - 1 : add_cnt)) {
            cnt = 0;
            if (direction_index >= 5) {
                ++add_cnt;
                direction_index = 0;
            }
            else {
                if (++direction_index == 1 && add_cnt == 1) {
                    ++direction_index;
                }
            }
        }
    }

    int c;  cin >> c;
    for (int i = 0; i < c; i++) {
        int n;  cin >> n;
        cout << answer[n - 1] << '\n';
    }

    return 0;
}