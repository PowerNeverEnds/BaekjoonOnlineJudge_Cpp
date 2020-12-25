#include <iostream>
using namespace std;

int main()
{
	int cnt = 0;
	char t;
	do
	{
		cin >> t;
		cnt++;
	} while (!cin.eof());
	cout << cnt - 1 << "\n";

	return 0;
}