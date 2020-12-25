#include <iostream>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int sum = 0;
	int min = 10000;
	for (int i = 0; i <= 100; i++)
	{
		if (M <= i * i && i * i <= N)
		{
			sum += i * i;
			min = i * i < min ? i * i : min;
		}
	}
	if (sum == 0)
		cout << -1 << "\n";
	else
	{
		cout << sum << "\n";
		cout << min << "\n";
	}

	return 0;
}