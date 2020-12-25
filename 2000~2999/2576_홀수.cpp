#include <iostream>

using namespace std;

int main()
{
	int e;
	int min=100;
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		cin >> e;
		if (e % 2 == 1)
		{
			sum += e;
			min = e < min ? e : min;
		}
	}
	if (min == 100)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << sum << "\n";
		cout << min << "\n";
	}
	
	return 0;
}