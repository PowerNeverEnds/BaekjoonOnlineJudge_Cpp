#include <iostream>

using namespace std;

int myMin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int min = 0;
	min = myMin(N / 2, M);
	int a = N + M - min * 3;
	if (a >= K)
	{
		cout << min << "\n";
	}
	else if (min - (K - a + 2) / 3 >= 0)
		cout << min - (K - a + 2) / 3 << "\n";
	else
		cout << 0 << "\n";

	return 0;
}