#include <iostream>

typedef long long ll;

using namespace std;

void dfs(int* arr, int* visited, int depth, int M, int N)
{
	if (depth > M)
	{
		for (int i = 1; i <= M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		arr[depth] = i;
		dfs(arr, visited, depth + 1, M, N);
		visited[i] = 0;
		//arr[depth]
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	int* visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);
	int* arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 1; i <= N; i++)
		arr[i] = i;

	dfs(arr, visited, 1, M, N);


	return 0;
}