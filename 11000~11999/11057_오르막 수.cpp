/*

1111a2bcdefg

n+9Cn

(n+9)!/(n+9-n)!n!

10!/9!1!
10

11!/9!2!

(n+9)!/9!n!
n+9*n+8...n+1/9!

*/

#include <iostream>

#define DIV (int(1e4+7))

using namespace std;

int multi(int x, int r)
{
	int result = 1;
	while (true)
	{
		if (r == 0)
			break;
		if (r % 2 == 1)
		{
			result *= x;
			result %= DIV;
		}
		x *= x;
		x %= DIV;
		r /= 2;
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	int result = 1;
	for (int i = 1; i <= 9; i++)
	{
		result = (result * (n + i)) % DIV;
	}

	//cout << result << "\n";
	int fac=1;
	for (int i = 1; i <= 9; i++)
		fac *= i;
	fac %= DIV;
	//cout << fac << "\n";
	result *= multi(fac, DIV-2 );
	result %= DIV;
	//cout << multi(fac, DIV - 2)<<"\n";
	cout << result << "\n";

	return 0;
}