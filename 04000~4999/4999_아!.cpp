/**
 *    BOJ 4999
 *    - ¾Æ!
 *    author:  phcdream
 *    created: ¿ÀÈÄ 9:04 2020-12-04
**/

#include <iostream>

using namespace std;

int main()
{
	int a=0;
	int b=0;
	char ch;
	while (true)
	{
		cin >> ch;
		if (ch == 'h')
			break;
		a++;
	}
	while (true)
	{
		cin >> ch;
		if (ch == 'h')
			break;
		b++;
	}
	if (a >= b)
		cout << "go" << "\n";
	else
		cout << "no" << "\n";

	return 0;
}