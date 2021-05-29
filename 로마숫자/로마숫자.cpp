#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string arabia_to_rome(int number) {
    int num_4 = number / 1000;
    int num_3 = (number - num_4 * 1000) / 100;
    int num_2 = (number - num_4 * 1000 - num_3 * 100) / 10;
    int num_1 = (number - num_4 * 1000 - num_3 * 100 - num_2 * 10);

    unordered_map<int, string> um_1 = {
        {0, ""}, {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"},
        {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}
    };

    unordered_map<int, string> um_2 = {
        {0, ""}, {1, "X"}, {2, "XX"}, {3, "XXX"}, {4, "XL"},
        {5, "L"}, {6, "LX"}, {7, "LXX"}, {8, "LXXX"}, {9, "XC"}
    };

    unordered_map<int, string> um_3 = {
        {0, ""}, {1, "C"}, {2, "CC"}, {3, "CCC"}, {4, "CD"},
        {5, "D"}, {6, "DC"}, {7, "DCC"}, {8, "DCCC"}, {9, "CM"}
    };

    unordered_map<int, string> um_4 = {
        {0, ""}, {1, "M"}, {2, "MM"}, {3, "MMM"}
    };

    return um_4[num_4] + um_3[num_3] + um_2[num_2] + um_1[num_1];
}

int rome_to_arabia(string& str) {
    unordered_map<char, int> um = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    unordered_map<string, int> um_2 = {
        {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
    };

    int result = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        if (um_2[str.substr(i,2)] > 0) {
            result += um_2[str.substr(i, 2)];
            ++i;
        }
        else {
            result += um[str[i]];
        }
    }

    if (str.length() == 1 || um_2[str.substr(str.size() - 2, 2)] == 0) {
        result += um[str.back()];
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);
    int T;  cin >> T;
    for (int i = 0; i < T; i++) {
        string s;   cin >> s;
        if (s.front() >= 'A' && s.front() <= 'Z') {
            cout << rome_to_arabia(s) << '\n';
        }
        else {
            cout << arabia_to_rome(atoi(s.c_str())) << '\n';
        }
    }

    return 0;
}