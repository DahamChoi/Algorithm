#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s = "BCDAF";
	string s2 = s;

	sort(s2.begin(), s2.end());

	int n = -1;
	int m = s.size();
	int fe = m - 1;

	while (n < m)
	{
		++n;
		for (int i = n; i <= fe; i++)
		{
			if (s[i] == s2[n])
			{
				reverse(s.begin() + n, s.begin() + i + 1);
				if (n == 0)
					fe = i;

				break;
			}
		}
	}

	cout << s << endl;
}