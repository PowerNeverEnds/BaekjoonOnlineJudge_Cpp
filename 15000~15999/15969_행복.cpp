/**
 *    BOJ 15969
 *    - 행복
 *    author:  phcdream
 *    created: 오전 3:29 2020-12-06
**/

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int max, min;
	max = 0;
	min = 1e3 + 7;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		max = e > max ? e : max;
		min = e < min ? e : min;
	}

	cout << max - min << "\n";

	return 0;
}