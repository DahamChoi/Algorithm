#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string original, bomb;
    cin >> original;
    cin >> bomb;

    vector<string> stack(1, "");
    for (int i = 0; i < original.length(); i++) {
        if (original[i] == bomb.front()) {
            stack.push_back(string(1, bomb.front()));
            if (stack.back() == bomb) {
                stack.pop_back();
            }
        }
        else {
            stack.back().push_back(original[i]);
            if (stack.back() == bomb) {
                stack.pop_back();
            }
        }
    }

    if (stack.size() == 1 && stack.back() == "") {
        cout << "FRULA";
    }
    else {
        for (auto& it : stack) {
            cout << it;
        }
    }

    return 0;
}