#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int e;
		cin >> e;
		sum += e;
	}
	
	cout << sum / 60 << "\n";
	cout << sum % 60 << "\n";

	return 0;
}