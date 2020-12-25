/**
 *    BOJ 4796
 *    - Ä·ÇÎ
 *    author:  phcdream
 *    created: ¿ÀÀü 5:05 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	for(int i=1;;i++)
	{
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		cout << "Case " << i << ": " << V / P * L + (V % P > L ? L : V % P) << "\n";
	}
	return 0;
}

/*
5 8 20
5 8 17
0 0 0

1 10 11
1 10 12
0 0 0
*/