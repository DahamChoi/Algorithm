#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 100;

    vector<unsigned long long> p = { 0,1 };
    for (int i = 2; i < n; i++) {
        p.push_back(p[i - 1] + p[i - 2]);
    }

    std::cout << p.back();
}