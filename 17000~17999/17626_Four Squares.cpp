#include <iostream>
using namespace std;

int mem[300] = { 0, };

int binarySearch(int n, int l = 0, int r = 225)
{
	int mid = (l + r) / 2;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (mem[mid] == n)
			return mid;
		if (mem[mid] < n)
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 225; i++)
	{
		mem[i] = i * i;
	}

	int n;
	cin >> n;

	if (binarySearch(n, 0, 225))
	{
		cout << 1 << "\n";
		return 0;
	}

	for (int i = 0; i < 225; i++)
	{
		if (n < i)
			break;
		if (binarySearch(n - i * i, 0, 225))
		{
			cout << 2 << "\n";
			return 0;
		}
	}

	for (int i = 0; i < 255; i++)
	{
		if (n < i)
			break;
		for (int j = i; j < 255; j++)
		{
			if (n < j)
				break;
			if (binarySearch(n - i * i - j * j, 0, 255))
			{
				cout << 3 << "\n";
				return 0;
			}
		}
	}

	cout << 4 << "\n";

	return 0;
}