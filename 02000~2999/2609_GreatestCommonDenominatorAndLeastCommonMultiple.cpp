#include <iostream>
using namespace std;

int gcd(int a, int b);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int gcdValue = gcd(a, b);
	cout << gcdValue << "\n";
	cout << a * b / gcdValue << "\n";

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