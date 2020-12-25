#include <iostream>

using namespace std;

int main()
{
	bool arr[31] = { 0, };
	for (int i = 0; i < 28; i++)
	{
		int e;
		cin >> e;
		arr[e] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (arr[i] == false)
			cout << i << "\n";
	}

	return 0;
}