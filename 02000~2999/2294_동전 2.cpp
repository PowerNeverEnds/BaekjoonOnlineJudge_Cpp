#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int* coin = new int[(ll)n + 1];
	fill(coin, coin + n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	sort(coin, coin + n, [](auto a, auto b) {
		return a < b;
		});

	int* dp = new int[(ll)k + 1];
	fill(dp, dp + k + 1, 0);
	for (int i = 0; i < n; i++)
		dp[coin[i]] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - coin[j] < 0 || coin[j] == coin[j + 1])
				continue;
			int pre = dp[i - coin[j]];
			if (pre != 0)
			{
				if (pre + 1 < dp[i] || dp[i] == 0)
					dp[i] = pre + 1;
			}
			//for (int t = 0; t <= k; t++)
			//	cout << dp[t] << " ";
			//cout << "\n";
		}
	}

	if (dp[k] == 0)
		cout << -1 << "\n";
	else
		cout << dp[k] << "\n";

	return 0;
}