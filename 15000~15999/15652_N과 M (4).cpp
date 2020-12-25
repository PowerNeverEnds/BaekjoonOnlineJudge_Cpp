#include <iostream>

using namespace std;

void dfs(int st, int depth, int N, int M, int* arr)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}cout << "\n";
		return;
	}

	for (int i = st; i <= N; i++)
	{
		arr[depth] = i;
		dfs(i, depth + 1, N, M, arr);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int arr[8] = { 0, };

	dfs(1, 0, N, M, arr);
	return 0;
}