/**
 *    BOJ 10801
 *    - 카드게임
 *    author:  phcdream
 *    created: 오후 11:34 2020-12-06
**/

#include <iostream>

using namespace std;

int main()
{
	int A[10] = { 0, };
	int cntA, cntB;
	cntA = cntB = 0;
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	for (int i = 0; i < 10; i++)
	{
		int e;
		cin >> e;
		if (A[i] > e)
			cntA++;
		else if (A[i] < e)
			cntB++;
	}
	if (cntA == cntB)
		cout << "D" << "\n";
	else if (cntA > cntB)
		cout << "A" << "\n";
	else if (cntA < cntB)
		cout << "B" << "\n";

	return 0;
}