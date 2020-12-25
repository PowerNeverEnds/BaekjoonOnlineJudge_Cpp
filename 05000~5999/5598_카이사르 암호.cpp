/**
 BOJ 5598
 - 카이사르 암호
 - 오전 12:05 2020-11-28
 */

#include <iostream>

using namespace std;

int main()
{
	char ch;
	while (cin >> ch)
	{
		cout << char(((ch - 'A') - 3 + 26) % 26 + 'A');
	}

	return 0;
}