/**
 *    BOJ 9325
 *    - 얼마?
 *    author:  phcdream
 *    created: 오전 7:17 2020-12-05
**/

#include <iostream>

using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int s;
		cin >> s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int q, p;
			cin >> q >> p;
			s += q * p;
		}
		cout << s << "\n";
	}

	return 0;
}