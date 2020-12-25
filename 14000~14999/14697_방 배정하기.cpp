/**
 *    BOJ 14697
 *    - 방 배정하기
 *    author:  phcdream
 *    created: 오전 12:56 2020-12-10
**/

#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	bool* dp = new bool[(ll)N + 1];
	fill(dp, dp + N + 1, false);

	int arr[3] = { A,B,C };
	dp[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (0 <= i - arr[j] && dp[i - arr[j]] == true)
				dp[i] = true;
		}
	}
	cout << dp[N] << "\n";

	return 0;
}