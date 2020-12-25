#include <iostream>

typedef long long ll;

#define INF ((int)(1e9))

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int** arr = new int* [(ll)n + 1];
	fill(arr, arr + n + 1, nullptr);
	for (int i = 0; i < n + 1; i++)
	{
		arr[i] = new int[(ll)n + 1];
		fill(arr[i], arr[i] + n + 1, INF);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] > c)
			arr[a][b] = c;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[i][i] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}cout << "\n";
	}

	return 0;
}