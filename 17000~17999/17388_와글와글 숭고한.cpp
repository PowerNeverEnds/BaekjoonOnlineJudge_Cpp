/**
 *    BOJ 17388
 *    - 와글와글 숭고한
 *    author:  phcdream
 *    created: 오후 8:54 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	int S, K, H;
	cin >> S >> K >> H;
	if (S + K + H >= 100)
	{
		cout << "OK" << "\n";
	}
	else
	{
		if (S < K && S < H)
		{
			cout << "Soongsil" << "\n";
		}
		else if (K < S && K < H)
		{
			cout << "Korea" << "\n";
		}
		else if (H < S && H < K)
		{
			cout << "Hanyang" << "\n";
		}
	}

	return 0;
}