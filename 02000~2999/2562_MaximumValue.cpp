#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[9] = { 0, };
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}
	int max = arr[0];
	int pMax = 0;
	for (int i = 0; i < 9; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			pMax = i;
		}
	}
	cout << max << "\n";
	cout << pMax + 1 << "\n";
	return 0;
}