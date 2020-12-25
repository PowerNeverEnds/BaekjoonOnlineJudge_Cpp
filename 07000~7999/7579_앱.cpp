/**
 *    BOJ 7579
 *    - ¾Û
 *    author:  phcdream
 *    created: ¿ÀÀü 12:51 2020-12-14
**/

#include <iostream>

typedef long long ll;

#define MAX ((int)1e4)

using namespace std;

struct MyStruct
{
	int m;
	int c;
};

int myMax(int a, int b)
{
	return a >= b ? a : b;
}

int myMin(int a, int b)
{
	return a <= b ? a : b;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	MyStruct* arr = new MyStruct[(ll)N + 1];
	fill(arr, arr + N + 1, MyStruct{ 0,0 });
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i].m;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i].c;
	}

	int** dp = new int* [2];
	fill(dp, dp + 2, nullptr);
	for (int i = 0; i < 2; i++)
	{
		dp[i] = new int[(ll)MAX + 1];
		fill(dp[i], dp[i] + MAX + 1, 0);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= MAX; j++)
		{
			if (j < arr[i].c)
			{
				dp[(i % 2)][j] = dp[!(i % 2)][j];
			}
			else if (arr[i].c <= j)
			{
				dp[(i % 2)][j] = myMax(arr[i].m + dp[!(i % 2)][j - arr[i].c], dp[!(i % 2)][j]);
			}
		}
		//for (int i = 0; i < 2; i++)
		//{
		//	for (int j = 0; j <= 20; j++)
		//	{
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}

	for (int i = 0; i <= MAX; i++)
	{
		if (dp[(N % 2)][i] >= M)
		{
			cout << i << "\n";
			break;
		}
	}

	delete[]arr;
	delete[]dp;

	return 0;
}