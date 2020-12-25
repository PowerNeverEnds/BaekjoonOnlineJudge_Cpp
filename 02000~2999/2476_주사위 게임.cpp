/**
 *    BOJ 2476
 *    - 주사위 게임
 *    author:  phcdream
 *    created:  오전 3:23 2020-11-30
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int sum;
		if (a == b && b == c)
			sum = 10000 + a * 1000;
		else if (a == b || b == c || c == a)
		{
			if (a == b)
				sum = 1000 + a * 100;
			else if (b == c)
				sum = 1000 + b * 100;
			else
				sum = 1000 + c * 100;
		}
		else
		{
			if (a > b)
			{
				if (a > c)
					sum = a * 100;
				else
					sum = c * 100;
			}
			else if (b > c)
			{
				sum = b * 100;
			}
			else
				sum = c * 100;
		}
		max = sum > max ? sum : max;
	}
	cout << max << "\n";

	return 0;
}