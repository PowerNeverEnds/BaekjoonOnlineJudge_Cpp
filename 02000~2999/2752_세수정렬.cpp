#include <iostream>

using namespace std;

void mySwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a > b)
		mySwap(a, b);
	if (b > c)
		mySwap(b, c);
	if (a > b)
		mySwap(a, b);

	cout << a <<" "<< b <<" "<< c << "\n";

	return 0;
}