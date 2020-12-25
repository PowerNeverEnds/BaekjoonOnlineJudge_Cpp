/**
 *    BOJ 3460
 *    - 이진수
 *    author:  phcdream
 *    created: 오전 3:13 2020-12-06
**/

#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; n >= 1 << i; i++)
		{
			if (n & 1 << i)
				cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}