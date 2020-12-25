#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int m = 10, n = 12;
		cin >> m >> n;
		int x = 0, y = 0;
		int a = 0, b = 0;
		cin >> x >> y;
		int i;
		a += x;
		b += x;
		b %= n;
		if (b == 0)
			b = n;
		for (i = 0; i < n+2; i++)
		{
			//cout << i << " " << a << " " << b << "\n";
			if (b == y)
			{
				cout << x + m * i << "\n";
				break;
			}
			b += m;
			b = b % n;
			if (b == 0)
				b = n;
		}
		if (!(b == y))
			cout << -1 << "\n";
	}

	return 0;
}