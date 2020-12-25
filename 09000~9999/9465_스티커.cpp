#include <iostream>

typedef long long ll;

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int** arr = new int* [3];
		fill(arr, arr + 3, nullptr);
		for (int i = 0; i < 3; i++)
		{
			arr[i] = new int[(ll)n + 1];
			fill(arr[i], arr[i] + n + 1, 0);
		}

		for (int j = 0; j < 2; j++)
			for (int i = 1; i <= n; i++)
			{
				cin >> arr[j][i];
			}

		int** dp = new int* [3];	// dp[i][2]는 아무것도 선택하지않았을때
		fill(dp, dp + 3, nullptr);
		for (int i = 0; i < 3; i++)
		{
			dp[i] = new int[(ll)n + 1];
			fill(dp[i], dp[i] + n + 1, 0);
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int a = dp[(j + 1) % 3][i - 1];
				int b = dp[(j + 2) % 3][i - 1];
				dp[j][i] = max(a, b) + arr[j][i];
			}

		}

		cout << max(max(dp[0][n], dp[1][n]), dp[2][n]) << "\n";

		delete[] arr;
	}
	return 0;
}