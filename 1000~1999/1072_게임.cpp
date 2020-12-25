/**
 *    BOJ 1072
 *    - 게임
 *    author:  phcdream
 *    created: 오전 8:39 2020-12-07
**/

#include <iostream>

typedef long long ll;

using namespace std;

ll binSearch(ll X, ll Y, ll Z)
{
	ll l = 0;
	ll r = X;
	ll mid;
	while (true)
	{
		if (l >= r)
			break;
		mid = (l + r) / 2;
		ll nZ = (Y + mid) * 100 / (X + mid);
		if (nZ < Z + 1)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return r;
}
int main()
{
	ll X, Y;
	cin >> X >> Y;
	ll Z;
	Z = Y * 100 / X;
	//cout << Z << "\n";
	if (Z >= 99)
		cout << -1 << "\n";
	else
	{
		ll re = binSearch(X, Y, Z);
		cout << re << "\n";
	}
	return 0;
}