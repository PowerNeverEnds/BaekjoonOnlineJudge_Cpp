#include <iostream>
using namespace std;

bool star(int n, int i, int j);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < i*2+1; j++)
		{
			if (star(n, i, j))
				cout << "*";
			else
				cout << " ";
		}
		for (int j = 0; j < n - i - 1; j++)
		{
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}

bool star(int n, int i, int j)
{
	if (n == 3)
	{
		if (i == 1 && j == 1)
			return false;
		return true;
	}
	else if ((n / 2)<=i && j < n && (i - n / 2)*2 < j)
	{
		return false;
	}
	else
	{
		star(n / 2, i%(n/2),j%(n/2));
	}
}