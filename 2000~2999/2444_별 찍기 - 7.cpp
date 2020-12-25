#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int d = 1;
	for (int i = 1; i >= 1; i+=d)
	{
		for (int j = n; j >i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < i * 2 - 1; j++)
		{
			cout << "*";
		}
		cout << "\n";
		if (i == n)
			d = -1;
	}
	return 0;
}