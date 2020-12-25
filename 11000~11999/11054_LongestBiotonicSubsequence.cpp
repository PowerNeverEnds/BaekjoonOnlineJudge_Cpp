#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int** count = new int* [n];
	for (int i = 0; i < n; i++)
	{
		count[i] = new int[2];
		count[i][0] = count[i][1] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				if (count[j][0] > count[i][0])
				{
					count[i][0] = count[j][0];
				}
			}
		}
		count[i][0] += 1;
	}
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = n-1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				if (count[i][1] < count[j][1])
				{
					count[i][1] = count[j][1];
				}
			}
		}
		count[i][1] += 1;
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < (count[i][0] + count[i][1]))
		{
			max = count[i][0] + count[i][1];
		}
	}
	cout << max - 1 << "\n";

	return 0;
}