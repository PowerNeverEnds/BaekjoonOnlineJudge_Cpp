/**
 *    BOJ 17404
 *    - RGB거리 2
 *    author:  phcdream
 *    created: 오전 5:31 2020-12-18
**/

#include <iostream>

typedef long long ll;

#define ALL false
#define dout if(true && ALL) cout
#define dfor if(true && ALL) for
#define INF ((int)1e6+7)

using namespace std;

int myMin(int a, int b)
{
	return a <= b ? a : b;
}

void in(int& N, int**& arr)
{
	cin >> N;
	arr = new int* [(ll)N + 1];
	fill(arr, arr + N + 1, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[(ll)3];
		fill(arr[i], arr[i] + 3, 0);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void print(int N, int***& arr)
{

	dfor(int k = 0; k < 3; k++)
	{
		dfor(int i = 0; i < N; i++)
		{
			dfor(int j = 0; j < 3; j++)
			{
				dout << arr[i][j][k] << " ";
			}
			dout << "\n";
		}
		dout << "\n";
	}
	dout << "\n";
}

int solve(int& N, int**& arr)
{
	int*** dp = new int** [(ll)N + 1];		// i j k	k는 첫번째에 k번째색을 선택했을때의 dp
	fill(dp, dp + N + 1, nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = new int* [(ll)3];
		fill(dp[i], dp[i] + 3, nullptr);
		for (int j = 0; j < 3; j++)
		{
			dp[i][j] = new int[3];
			fill(dp[i][j], dp[i][j] + 3, INF);
		}
	}

	dp[0][0][0] = arr[0][0];
	dp[0][1][1] = arr[0][1];
	dp[0][2][2] = arr[0][2];

	for (int i = 0 + 1; i < N; i++)
	{
		print(N, dp);
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (i == N - 1 && j == k)
					continue;
				dp[i][j][k] = arr[i][j] + myMin(dp[i - 1][(j + 1) % 3][k], dp[i - 1][(j + 2) % 3][k]);
			}
		}
	}

	print(N, dp);

	int min = INF;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int e = dp[N - 1][i][j];
			if (e < min)
				min = e;
		}
	}

	return min;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int** arr;
	in(N, arr);

	int re = solve(N, arr);
	cout << re << "\n";

	return 0;
}