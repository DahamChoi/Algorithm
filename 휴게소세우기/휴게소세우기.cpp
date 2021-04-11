#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct C
{
	int length, origin, div;
};

int main()
{
	int n;
	int m;
	int l;
	vector<int> v;

	cin >> n;
	cin >> m;
	cin >> l;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	
	v.insert(v.begin(), 0);
	v.push_back(l);

	vector<C> pv;
	for (int i = 0; i < v.size() - 1; i++)
		pv.push_back({ v[i + 1] - v[i], v[i + 1] - v[i], 1 });

	while (m-- > 0)
	{
		sort(pv.begin(), pv.end(), [](const C& c1, const C& c2) {
			return (c1.length > c2.length);
			});

		C& c = pv[0];
		pv[0] = { (int)ceil((float)c.origin / (float)(c.div + 1)), c.origin, c.div + 1 };
	}

	sort(pv.begin(), pv.end(), [](const C& c1, const C& c2) {
		return (c1.length > c2.length);
		});

	cout << pv[0].length;
}