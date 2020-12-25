/**
 *    BOJ 3067
 *    - Coins
 *    author:  phcdream
 *    created: ¿ÀÀü 3:03 2020-12-08
**/

#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int* arr = new int[(ll)N+1];
		fill(arr, arr + N+1, 0);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		int M;
		cin >> M;
		int** dp = new int*[(ll)N+1];
		fill(dp, dp + N+1, nullptr);
		for (int i = 0; i <N+1; i++)
		{
			dp[i] = new int[(ll)M+1];
			fill(dp[i], dp[i] + M + 1, 0);
		}
		for (int i = 1; i <= N; i++)
		{
			dp[i][arr[i]] = 1;
			for (int j = 1; j <= M; j++)
			{
				if (j >= arr[i])
					dp[i][j] += dp[i - 1][j - arr[i]] + dp[i][j-arr[i]];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cout << dp[i][j] << " ";
			}cout << "\n";
		}cout << "\n";
		int sum = 0;
		for (int i = 0; i <= N; i++)
		{
			sum += dp[i][M];
		}
		cout << sum << "\n";
		
		delete[] arr;
		delete[] dp;
	}
	return 0;
}
/*
3
2
1 2
1000
3
1 5 10
100
2
5 7
22

1
2
1 2
10

1
3
1 5 10
100
*/