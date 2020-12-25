#include <iostream>

using namespace std;


int main()
{
	int N;
	cin >> N;
	int dp[31][3]={0,};
	
	dp[2][0] = 3;
	dp[2][2] = dp[2][0];
	dp[4][0] = 9;
	dp[4][1] = 2;
	dp[4][2] = dp[4][0]+dp[4][1];
	dp[0][2] = 1;
	for (int i = 5; i <= N; i++)
	{
		dp[i][0] = (dp[i-2][2]) * 3;
		for (int j = 4; i-j>=0; j+=2)
		{
			dp[i][1] += (dp[i - j][2]) * 2;
		}
		dp[i][2] = dp[i][0] + dp[i][1];
	}
	//for (int i = 1; i <= N; i++)
	//{
	//	cout << dp[i][0] << " " << dp[i][1]<<" "<<dp[i][2] << "\n";
	//}
	cout << dp[N][2] << "\n";

	return 0;
}