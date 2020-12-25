#include <iostream>

using namespace std;

int main()
{
	char ch;
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> ch;
			if (!((i % 2 + j) % 2) && ch == 'F')
				cnt++;

		}
	}

	cout << cnt << "\n";

	return 0;
}