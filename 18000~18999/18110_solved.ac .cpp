#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n;
	cin >> n;
	if (n == 0)
	{
		cout << "0" << "\n";
		return 0;
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, [](auto a, auto b) {
		return a < b;
		});

	int cut = int(0.15 * n + 0.5);
	int sum = 0;
	for (int i = cut; i < n - cut; i++)
	{
		sum += arr[i];
	}
	int answer = int(1.0 * sum / ((long long)n - (long long)cut * 2) + 0.5);
	cout << answer << "\n";

	return 0;
}