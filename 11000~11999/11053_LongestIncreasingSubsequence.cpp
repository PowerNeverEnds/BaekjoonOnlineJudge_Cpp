#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int* arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int* count = new int[n + 1];

	int longest = 0;

	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				if (max < count[j])
				{
					max = count[j];
				}
			}
		}
		count[i] = max + 1;
		if (longest < count[i])
		{
			longest = count[i];
		}
	}

	cout << longest << "\n";

	return 0;
}