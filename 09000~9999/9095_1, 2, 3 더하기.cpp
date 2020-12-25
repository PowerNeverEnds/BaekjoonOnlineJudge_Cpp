#include <iostream>
using namespace std;

int dp[12][4];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][3] = 1;

	for (int i = 1; i <= 11; i++)
	{
		int a, b, c;
		for (int j = 1; j <= 3; j++)
		{
			if (i > j)
			{
				a = dp[i - j][1];
				b = dp[i - j][2];
				c = dp[i - j][3];
				dp[i][j] = a + b + c;
			}
		}

	}
	//for (int i = 0; i <= 11; i++)
	//{
	//	for (int j = 0; j <= 3; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int a, b, c;
		a = dp[n][1];
		b = dp[n][2];
		c = dp[n][3];
		cout << a + b + c << "\n";
	}
	return 0;
}