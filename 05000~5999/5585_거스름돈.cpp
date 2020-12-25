#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[6] = { 500,100,50,10,5,1 };
	int cnt = 0;

	n = 1000 - n;
	for (int i = 0; i < 6; i++)
	{
		if (n == 0)
			break;
		cnt = cnt + (n / arr[i]);
		n %= arr[i];
	}

	cout << cnt << "\n";

	return 0;
}