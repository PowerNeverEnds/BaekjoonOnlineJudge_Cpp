#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int e;
		cin >> e;
		if (e < 40)
			e = 40;
		sum += e;
	}

	cout << sum / 5 << "\n";

	return 0;
}