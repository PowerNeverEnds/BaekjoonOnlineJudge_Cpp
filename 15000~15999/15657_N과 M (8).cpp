#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

void dfs(int depth, int prev, int* num, int* arr, int N, int M)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}cout << "\n";
		return;
	}
	else
	{
		for (int i = prev; i < N; i++)
		{
			arr[depth] = num[i];
			dfs(depth + 1, i, num, arr, N, M);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	int* num = new int[(ll)N];
	fill(num, num + N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	int* arr = new int[(ll)N];
	fill(arr, arr + N, 0);


	sort(num, num + N, [](auto a, auto b) {
		return a < b;
		});

	dfs(0, 0, num, arr, N, M);
	return 0;
}