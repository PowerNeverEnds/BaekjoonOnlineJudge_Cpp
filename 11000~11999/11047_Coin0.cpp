#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int arr[10] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (k / arr[i] != 0)
		{
			count += k / arr[i];
			k %= arr[i];
		}
	}

	cout << count << "\n";

	return 0;
}