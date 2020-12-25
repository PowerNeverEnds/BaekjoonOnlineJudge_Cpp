#include <iostream>
using namespace std;

bool star(int n, int r, int c);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (star(n, i, j))
			{
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}

bool star(int n, int r, int c)
{
	if ((n/3 <= r && r < n/3*2)  &&(n/3 <= c && c < n/3*2))
	{
		return false;
	}
	else
	{
		if (n == 1)
		{
			return true;
		}
		return (star(n / 3, r%(n/3), c%(n/3)));
	}
}