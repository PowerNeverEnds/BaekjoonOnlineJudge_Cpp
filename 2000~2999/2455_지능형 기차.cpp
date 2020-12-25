#include <iostream>
using namespace std;

int main()
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int a, b;
		cin >> a >> b;
		sum = sum - a + b;
		max = sum > max ? sum : max;
	}

	cout << max << "\n";

	return 0;
}