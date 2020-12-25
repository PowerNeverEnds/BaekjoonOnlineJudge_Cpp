#include <iostream>

using namespace std;

int main()
{
	char ch;
	int cnt = 0;
	while (true)
	{
		cin >> ch;
		if (cin.eof())
			break;
		switch (ch)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			cnt++;
			break;
		default:
			break;
		}
	}

	cout << cnt << "\n";

	return 0;
}