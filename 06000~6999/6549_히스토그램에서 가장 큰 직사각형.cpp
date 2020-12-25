#include <iostream>
typedef unsigned long long ull;
using namespace std;

ull histogram(int* arr, int l, int r)
{
	if (l == r)
	{
		return arr[l];
	}
	else if (l + 1 == r)
	{
		return arr[l] < arr[r] ? arr[l] : arr[r];
	}
	else
	{
		histogram(arr, l, (l + r) / 2);
		histogram(arr, (l + r) / 2, r);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = -1;
	while (n != 0)
	{
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		histogram(arr, 0, n);

	}

	return 0;
}