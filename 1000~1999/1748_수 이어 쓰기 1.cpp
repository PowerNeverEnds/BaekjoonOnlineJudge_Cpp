#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	ll n;
	cin >> n;
	ll x = 1;
	ll y = 1;
	ll sum = 0;
	while (true)
	{
		if (n < x * 10)
			break;
		x *= 10;
		sum += (x - x / 10) * y;
		y++;
	}
	//cout << sum << "\n";
	sum = sum + (n - (x - 1)) * y;
	cout << sum << "\n";

	return 0;
}