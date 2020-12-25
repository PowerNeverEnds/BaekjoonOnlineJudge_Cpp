#include <iostream>
using namespace std;

int gcd(int a, int b);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a;
	cin >> a;
	for (int i = 1; i < n; i++)
	{
		int b;
		cin >> b;
		int c = gcd(a, b);
		cout << a / c << "/" << b / c << "\n";

	}

	return 0;
}

int gcd(int a, int b)
{
	int t;
	while (b)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}