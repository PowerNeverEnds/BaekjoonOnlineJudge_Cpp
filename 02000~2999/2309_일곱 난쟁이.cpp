#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[9] = { 0, };
	int sum = 0;
	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	for (int i = 0; i < 9; i++)
		sum += arr[i];
	bool find = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				arr[i] = 100;
				arr[j] = 100;
				find = true;
				break;
			}
		}
		if (find == true)
			break;
	}
	sort(arr, arr + 9, [](auto a, auto b) {
		return a < b;
		});

	for (int i = 0; i < 7; i++)
		cout << arr[i] << "\n";

	return 0;
}