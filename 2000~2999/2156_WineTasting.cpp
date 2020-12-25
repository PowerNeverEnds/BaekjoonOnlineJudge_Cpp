#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int** arr = new int*[10001];
	for (int i = 0; i < 10001; i++)
	{
		arr[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0];
	}
	{
		arr[0][1] = arr[0][0];
		arr[0][2] = arr[0][0];
		arr[1][1] = arr[1][0] + arr[0][2];
		arr[1][2] = arr[1][0];
		arr[2][1] = arr[2][0] + arr[1][2];
		arr[2][2] = arr[2][0] + (arr[0][1] > arr[0][2] ? arr[0][1] : arr[0][2]);

	}
	for (int i = 3; i < n; i++)
	{
		arr[i][1] = arr[i][0] + (arr[i - 1][2] > arr[i - 1][3] ? arr[i - 1][2] : arr[i - 1][3]);
		
		arr[i][2] = arr[i][0] + max({ arr[i - 2][1], arr[i - 2][2], arr[i - 2][3] });

		arr[i][3] = arr[i][0] + (arr[i - 3][1] > arr[i - 3][2] ? arr[i - 3][1] : arr[i - 3][2]);
	}
	

	int max = 0;
	if (n >= 2)
	{
		max = arr[n - 2][1];
	}
	max = max > arr[n - 1][1] ? max : arr[n - 1][1];
	max = max > arr[n - 1][2] ? max : arr[n - 1][2];
	cout << max << "\n";

	return 0;
}