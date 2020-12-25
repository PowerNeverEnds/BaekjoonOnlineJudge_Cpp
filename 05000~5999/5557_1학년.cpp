#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int* arr = new int[(ll)N + 1];
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	ll** dp = new ll * [(ll)N + 1];
	fill(dp, dp + N + 1, nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = new ll[21];
		fill(dp[i], dp[i] + 21, 0);
	}

	dp[1][arr[1]] = 1;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			int prevL = j - arr[i];
			int prevR = j + arr[i];
			if (0 <= prevL)
			{
				dp[i][j] += dp[i - 1][prevL];
			}
			if (prevR <= 20)
			{
				dp[i][j] += dp[i - 1][prevR];
			}
		}
	}
	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j <= 21; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}cout << "\n";
	//}

	cout << dp[N - 1][arr[N]] << "\n";

	return 0;
}