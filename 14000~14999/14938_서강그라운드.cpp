#include <iostream>

typedef long long ll;

#define INF ((int)1e9+7)

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;
	int* arr = new int[(ll)n + 1];
	fill(arr, arr + n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int** graph = new int* [(ll)n + 1];
	fill(graph, graph + n + 1, nullptr);
	for (int i = 0; i < n + 1; i++)
	{
		graph[i] = new int[(ll)n + 1];
		fill(graph[i], graph[i] + n + 1, INF);
	}
	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}
	for (int i = 1; i <= n; i++)
	{
		graph[i][i] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		//sum += arr[i];
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] <= m)
			{
				sum += arr[j];
			}
		}
		max = sum > max ? sum : max;
	}

	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//	{
	//		cout << graph[i][j]<<" ";
	//	}cout << "\n";
	//}

	cout << max << "\n";

	return 0;
}