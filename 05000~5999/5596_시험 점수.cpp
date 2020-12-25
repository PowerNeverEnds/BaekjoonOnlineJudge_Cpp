/**
 *    BOJ 5596
 *    - 시험 점수
 *    author:  phcdream
 *    created: 오전 12:47 2020-12-03
**/

#include <iostream>

using namespace std;

int main()
{
	int sum[2] = { 0, };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int e;
			cin >> e;
			sum[i] += e;
		}
	}
	cout << (sum[0] >= sum[1] ? sum[0] : sum[1]) << "\n";


	return 0;
}