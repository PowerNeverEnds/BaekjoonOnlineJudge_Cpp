#include <iostream>

typedef long long ll;

using namespace std;

void dfs(int* visited, int depth, int N, int M)
{
	if (depth > M)
	{
		for (int i = 1; i <= M; i++)
			cout << visited[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		visited[depth] = i;
		dfs(visited, depth + 1, N, M);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	//int* arr = new int[(ll)N + 1];
	//fill(arr, arr + N + 1, 0);
	//for (int i = 1; i <= N; i++)
	//	arr[i] = i;	

	int* visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);

	dfs(visited, 1, N, M);

	return 0;
}