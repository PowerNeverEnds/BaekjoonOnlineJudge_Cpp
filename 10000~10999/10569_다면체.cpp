/**
 *    BOJ 10569
 *    - 다면체
 *    author:  phcdream
 *    created: 오전 4:30 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int V, E;
		cin >> V >> E;
		cout << 2 - V + E << "\n";
	}

	return 0;
}