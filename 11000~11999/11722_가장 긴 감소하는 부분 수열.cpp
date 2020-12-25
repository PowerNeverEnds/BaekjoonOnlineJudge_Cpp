/**
 BOJ 11722
 - 가장 긴 감소하는 부분 수열
 - 오후 10:50 2020-11-27
 */

#include <iostream>

typedef long long ll;

using namespace std;

void init(int& N, int*& arr, int*& dp)
{
	cin >> N;
	arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	dp = new int[(ll)N + 1];
	fill(dp, dp + N + 1, 1);
	
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
}

int solve(int& N, int*& arr, int*& dp)
{
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] > arr[i])
			{
				if (dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		max = dp[i] > max ? dp[i] : max;
	}

	return max;
}

void print(int& N, int*& arr)
{
	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	int* dp;
	init(N, arr, dp);

	int re = solve(N, arr, dp);

	//print(N,dp);

	cout << re << "\n";

	return 0;
}

/*
6
10 30 10 20 20 10

10
1 5 4 2 1 6 4 3 2 1

*/