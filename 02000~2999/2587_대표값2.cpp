#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int sum = 0;
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		int e;
		cin >> e;
		sum += e;
		arr[i] = e;
	}
	sort(arr, arr + 5, [](auto a, auto b) {
		return a < b;
		});

	cout << sum / 5 << "\n";
	cout << arr[2] << "\n";

	return 0;
}