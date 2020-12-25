/**
 *    BOJ 3034
 *    - 앵그리 창영
 *    author:  phcdream
 *    created: 오전 2:15 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	int N, W, H;
	cin >> N >> W >> H;
	int sum = W * W + H * H;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		if (e * e <= sum)
		{
			cout << "DA" << "\n";
		}
		else
			cout << "NE" << "\n";

	}
	return 0;
}