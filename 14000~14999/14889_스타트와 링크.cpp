#include <iostream>

typedef long long ll;

#define MAX ((int)1e7+7)

using namespace std;

int myAbs(int a, int b)
{
	return a > b ? a - b : b - a;
}

int dfs(int** arr, bool* visited, int depth, int N, int cnt)
{
	int min = MAX;
	if (depth > N)
	{
		//for (int i = 1; i <= N; i++)
		//{
		//	cout << visited[i] << " ";
		//}cout << "\n";
		int sum[2] = { 0, };
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				//if (!(visited[i] ^ visited[j]))
				if (visited[i] == visited[j])
				{
					sum[visited[i]] += arr[i][j];
				}
			}
		}
		//cout << sum[0] << " " << sum[1] << "\n";
		int diff = myAbs(sum[0], sum[1]);
		min = diff < min ? diff : min;

		return min;
	}
	for (int i = 0; i < 2; i++)
	{
		visited[depth] = i;
		if (i == 1)
			cnt++;
		if (cnt > N / 2 || depth - cnt > N / 2)
			continue;
		int diff = dfs(arr, visited, depth + 1, N, cnt);
		min = diff < min ? diff : min;
		//visited[depth] = !i;
	}

	return min;
}

int main()
{
	int N;
	cin >> N;
	int** arr = new int* [(ll)N + 1];
	fill(arr, arr + N + 1, nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[(ll)N + 1];
		fill(arr[i], arr[i] + N + 1, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool* visited = new bool[(ll)N + 1];
	fill(visited, visited + N + 1, NULL);

	int min = dfs(arr, visited, 1, N, 0);

	cout << min << "\n";

	delete[] arr;

	return 0;
}



/*
#include <iostream>

using namespace std;


void select(int n,int sel[], int arr[][21], int max)
{
	if (n >= max/2+1)
		return;
	for (int i = sel[n-1]+1; i < max; i++)
	{
		sel[n] = i;
		select(n + 1, sel, arr, max);
		if (n == max/2)
		{
			//for (int j = 0; j < 10; j++)
			//	cout << sel[j] << " ";
			//cout << "\n";
		}
	}
}

int main()
{

	int n;
	cin >> n;
	int arr[21][21];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int sel[21] = { 0, };
	select(1,sel, arr,n);

	return 0;
}
*/