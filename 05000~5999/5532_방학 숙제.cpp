#include <iostream>

using namespace std;

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;

	cout << L - (myMax((A - 1) / C, (B - 1) / D) + 1) << "\n";

	return 0;
}