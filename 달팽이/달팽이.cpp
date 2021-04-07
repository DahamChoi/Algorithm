#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> ar(n * n);
    int x = n / 2, y = n / 2;
    int dx = 1, dy = 1;
    int num = 1;

    while (true)
    {
        for (int i = y; y > i - dx; --y)
        {
            ar[y * n + x] = num++;
        }
        ++dy;

        if (num >= n * n)
            break;

        for (int i = x; x < i + dx; x++)
        {
            ar[y * n + x] = num++;
        }
        ++dx;

        for (int i = y; y < i + dx; y++)
        {
            ar[y * n + x] = num++;
        }
        ++dy;

        for (int i = x; x > i - dx; x--)
        {
            ar[y * n + x] = num++;
        }
        ++dx;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i * n + j] << " ";
        }
        cout << endl;
    }
}