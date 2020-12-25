#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int* arr, int num, int depth, int M, int N, int* c)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[c[i]] << " ";
		}cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		int use = false;
		for (int j = 0; j < depth; j++)
		{
			if (c[j] == i)
			{
				use = true;
				break;
			}
		}
		if (use)
		{
		}
		else
		{
			c[depth] = i;
			dfs(arr, i, depth + 1, M, N, c);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	int* arr = new int[N];
	fill(arr, arr + N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int* c = new int[N];
	fill(c, c + N, 0);
	for (int i = 0; i < N; i++)
		c[i] = i;

	sort(arr, arr + N, [](auto a, auto b) {
		return a < b;
		});

	dfs(arr, 0 - 1, 0, M, N, c);

	return 0;
}