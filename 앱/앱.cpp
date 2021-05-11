#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> memory(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }



    std::cout << "Hello World!\n";
}