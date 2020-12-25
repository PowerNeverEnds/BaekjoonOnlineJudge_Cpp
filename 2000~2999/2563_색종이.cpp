#include <iostream>

using namespace std;

int arr[100][100];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = y; j < y + 10; j++)
		{
			fill(arr[j] + x, arr[j] + x + 10, 1);
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
				cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}