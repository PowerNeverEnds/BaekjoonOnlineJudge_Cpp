#include <iostream>

using namespace std;

int main()
{
	int sTen;
	cin >> sTen;

	int sNine = 0;
	for (int i = 0; i < 9; i++)
	{
		int e;
		cin >> e;
		sNine += e;
	}

	cout << sTen - sNine << "\n";

	return 0;
}