#include <iostream>
#include <cmath>
using namespace std;

void swap(int& a, int& b);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a > b)
			swap(a, b);
		if (b > c)
			swap(b, c);
		if (a > b)
			swap(a, b);
		if ((pow(a, 2) + pow(b, 2)) == pow(c, 2))
		{
			cout << "right" << "\n";
		}
		else
			cout << "wrong" << "\n";
	}

	return 0;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}