#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N, [](auto a, auto b) {
		return a>b;
		});

	int sum = 0;
	for (int i = 0; i < N / 2; i++)
	{
		sum += arr[i] * 2;
		//cout << arr[i] << " " << sum << "\n";
	}
	if (N % 2 == 1)
	{
		sum += arr[N / 2];
	}

	cout << sum << "\n";

	return 0;
}