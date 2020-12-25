#include <iostream>

typedef long long ll;

using namespace std;

ll dp[1001][3];
ll arr[1001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0][0] = arr[0];
	for (int i = 0; i < N; i++)
	{
		int a = dp[i][0];
		int b = dp[i - 1][1];
		int c = dp[i - 2][2];
		int c = dp[i - 2][2];

		dp[i][0]=
	}
	return 0;
}