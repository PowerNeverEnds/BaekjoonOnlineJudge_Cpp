/**
 *    BOJ 1562
 *    - 계단 수
 *    author:  phcdream
 *    created: 오전 2:41 2020-12-04
**/

#include <iostream>

typedef long long ll;

#define DIV (int(1e9))

using namespace std;

void solve(int N)
{
	int** dp = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		dp[i] = new int[(ll)N + 1];
		fill(dp[i], dp[i] + N + 1, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		//for(int j)
	}
}

int main()
{
	int N;
	cin >> N;
	
	solve(N);


	return 0;
}