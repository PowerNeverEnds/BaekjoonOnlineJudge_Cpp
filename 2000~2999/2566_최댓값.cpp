#include <iostream>

using namespace std;

int main()
{
	int y, x;
	int max = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int e;
			cin >> e;
			if (e > max)
			{
				max = e;
				y = i;
				x = j;
			}
		}
	}

	cout << max << "\n";
	cout << y << " " << x << "\n";

	return 0;
}