#include <iostream>

#define MAX 1000

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int min6, min1;
	min6 = min1 = MAX;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		min6 = a < min6 ? a : min6;
		min1 = b < min1 ? b : min1;
	}

	int a, b;
	a = N / 6 * min6 + N % 6 * min1;
	b = N * min1;
	a = (a < b ? a : b);
	b = N / 6 * min6 + min6;
	a = (a < b ? a : b);

	cout << a << "\n";


	return 0;
}