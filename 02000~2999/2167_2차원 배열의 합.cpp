#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int** sum = new int* [(ll)N + 2];
	fill(sum, sum + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		sum[i] = new int[(ll)M + 2];
		fill(sum[i], sum[i] + M + 2, 0);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int K;
	cin >> K;
	int* out = new int[(ll)K];
	for (int k = 0; k < K; k++)
	{
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int a = sum[x][y];
		int b = sum[i - 1][j - 1];
		int c = sum[x][j - 1];
		int d = sum[i - 1][y];

		out[k] = a - c - d + b;
	}
	
	for(int i=0;i<K;i++)
	{ 
		cout << out[i] << "\n";
	}

	return 0;
}