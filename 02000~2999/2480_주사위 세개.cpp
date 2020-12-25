#include <iostream>

using namespace std;

int myMax(int a, int b, int c)
{
	return a > b ? a > c ? a : c : b > c ? b : c;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c)
	{
		cout << 10000 + a * 1000 << "\n";
	}
	else if (a == b || a == c || b == c)
	{
		int same;
		if (a == b || a==c)
			same = a;
		else if (b == c)
		{
			same = b;
		}
		cout << 1000 + same * 100 << "\n";
	}
	else
	{
		cout << myMax(a, b, c)*100 << "\n";
	}

	return 0;
}

/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

*/