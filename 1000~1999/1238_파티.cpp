#include <iostream>

typedef long long ll;

#define INF ((int)(1e9))

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M, X;
	cin >> N >> M >> X;
	int** arr = new int*[(ll)N + 1];
	fill(arr, arr + N + 1, nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[(ll)N + 1];
		fill(arr[i], arr[i] + N + 1, INF);
	}
	for (int i = 0; i <= N; i++)
	{
		arr[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int A, B, T;
		cin >> A >> B >> T;
		arr[A][B] = T;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		sum = arr[i][X] + arr[X][i];
		max = sum > max ? sum : max;
	}

	cout << max << "\n";

	return 0;
}