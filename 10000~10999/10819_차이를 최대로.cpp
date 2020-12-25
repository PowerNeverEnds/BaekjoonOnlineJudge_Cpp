#include <iostream>
#include <algorithm>

using namespace std;

int myAbs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	int n;
	cin >> n;
	int arr[8] = { 0, };
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int max = 0;
	sort(arr, arr + n, [](auto a, auto b) {
		return a < b;
		});
	do
	{
		int sum = 0;
		for (int i = 1; i < n; i++)
		{
			sum += myAbs(arr[i - 1] - arr[i]);
		}
		//for (int i = 0; i < n; i++) {
		//	cout << arr[i] << " ";
		//}cout << "\n";
		max = sum > max ? sum : max;

	} while (next_permutation(arr,arr+n));

	cout << max << "\n";

	return 0;
}