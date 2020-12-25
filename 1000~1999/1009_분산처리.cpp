#include <iostream>

#define DIV (10)

using namespace std;

int pow(int a, int b)
{
	int r = 1;
	while (b)
	{
		//if (b % 2 == 0)
		//{
		//}
		if (b % 2 == 1)
		{
			r = (r * a) % DIV;
			//b -= 1;
		}
		a = (a * a) % DIV;
		b /= 2;
	}
	return r;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		cout << (pow(a, b) + DIV - 1) % DIV + 1 << "\n";
	}

	return 0;
}