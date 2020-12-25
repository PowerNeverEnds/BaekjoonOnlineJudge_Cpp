/**
 *    BOJ 9625
 *    - BABBA
 *    author:  phcdream
 *    created: ¿ÀÀü 6:42 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	//for (int j = 0; j < 46; j++)
	//{

		int K;
		cin >> K;
		//K = j;
		int a, b;
		a = 1;
		b = 0;
		for (int i = 0; i < K; i++)
		{
			int t = a;
			a = b;
			b = t + b;
		}
		cout << a << " " << b << "\n";
	//}
	return 0;
}