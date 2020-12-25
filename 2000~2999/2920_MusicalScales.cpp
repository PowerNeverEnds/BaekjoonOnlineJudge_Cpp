#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int number;
	cin >> number;
	if (number == 1)
	{
		for (int i = 2; i <= 8; i++)
		{
			cin >> number;
			if (number != i)
			{
				cout << "mixed" << "\n";
				return 0;
			}
		}
	}
	else if (number == 8)
	{
		for (int i = 7; i >= 1; i--)
		{
			cin >> number;
			if (number != i)
			{
				cout << "mixed" << "\n";
				return 0;
			}
		}
	}
	if (number == 8)
	{
		cout << "ascending" << "\n";
	}
	else if (number == 1)
	{
		cout << "descending" << "\n";
	}

	return 0;
}