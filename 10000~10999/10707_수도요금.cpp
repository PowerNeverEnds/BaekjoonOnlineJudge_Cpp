/**
 BOJ 10707
 - 수도요금
 - 오전 2:22 2020-11-29
 */

#include <iostream>

using namespace std;

int myMin(int a, int b)
{
	return a < b ? a : b;
}

void init(int& A, int& B, int& C, int& D, int& P)
{
	cin >> A >> B >> C >> D >> P;
}

int solve(int A, int B, int C, int D, int P)
{
	int X = A * P;
	int Y;
	if (P <= C)
		Y = B;
	else
		Y = B + (P - C) * D;

	return myMin(X, Y);
}
int main()
{
	int A, B, C, D, P;
	init(A, B, C, D, P);

	int re = solve(A, B, C, D, P);
	cout << re << "\n";

	return 0;
}