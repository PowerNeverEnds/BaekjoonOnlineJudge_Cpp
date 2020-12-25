#include <iostream>

typedef long long ll;

using namespace std;


int main()
{
	int n;
	cin >> n;
	ll** dp = new ll* [(ll)n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new ll[2];
		fill(dp[i], dp[i] + 2, 0);
	}
	
	dp[0][1] = 1;

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n - 1][0] + dp[n - 1][1] << "\n";


	return 0;
}