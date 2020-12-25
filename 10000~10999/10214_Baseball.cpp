/**
 *    BOJ 10214
 *    - Baseball
 *    author:  phcdream
 *    created: ¿ÀÀü 12:14 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int y,k;
		int sumY, sumK;
		sumY = sumK = 0;
		for (int i = 0; i < 9; i++)
		{
			cin >> y >> k;
			sumY += y;
			sumK += k;
		}
		if (sumY < sumK)
			cout << "Korea" << "\n";
		else if (sumY > sumK)
		{
			cout << "Yonsei" << "\n";

		}
		else if (sumY == sumK)
			cout << "Draw" << "\n";
	}

	return 0;
}