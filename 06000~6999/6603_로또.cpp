/*

https://www.acmicpc.net/source/4407799

*/

#include <iostream>

typedef long long ll;

using namespace std;

void dfs(int s, int* arr, int* visited, int d, int dMax, int n)
{
	if (d > dMax)
		return;
	for (int i = s; i <= n; i++)
	{
		visited[d] = i;
		if (d == dMax)
		{
			for (int j = 1; j <= dMax; j++)
			{
				cout << arr[visited[j]] << " ";
			}cout << "\n";
		}
		dfs(i + 1, arr, visited, d + 1, dMax, n);
	}
}
int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		int* data = new int[(ll)n + 1];
		fill(data, data + n + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> data[i];
		int* visited = new int[(ll)n + 1];
		fill(visited, visited + n + 1, 0);

		dfs(1, data, visited, 1, 6, n);
		cout << "\n";

	}
	return 0;
}