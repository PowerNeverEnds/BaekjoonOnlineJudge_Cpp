#include <iostream>

typedef long long ll;

using namespace std;

bool defIsOk(int** arr, int i, int j, int N, int* xVisited, int* diagonalVisited)
{
	if (xVisited[j] == 1)
		return false;
	if (diagonalVisited[i - j + N] == 1)
		return false;
	for (int k = 0; k < i; k++)
	{
		if (arr[i - k][j] == 1)
		{
			return false;
		}
		if (1 <= j - k && arr[i - k][j - k] == 1)
			return false;
		if (j + k <= N && arr[i - k][j + k] == 1)
			return false;
	}
	return true;
}

int dfs(int** arr, int depth, int N, int* xVisited, int* diagonalVisited)
{
	int cnt = 0;
	if (depth > N)
	{
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//		cout << arr[i][j] << " ";
		//	cout << "\n";
		//}cout << "\n";
		return 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (defIsOk(arr, depth, i, N, xVisited, diagonalVisited) == false)
		{
			continue;
		}
		else
		{
			arr[depth][i] = 1;
			xVisited[i] = 1;
			diagonalVisited[depth - i + N] = 1;
			cnt += dfs(arr, depth + 1, N, xVisited, diagonalVisited);
			arr[depth][i] = 0;
			xVisited[i] = 0;
			diagonalVisited[depth - i + N] = 0;
		}
	}
	return cnt;
}

int main()
{
	int N;
	cin >> N;

	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, 0);
	}
	int* xVisited = new int[(ll)N + 2];
	fill(xVisited, xVisited + N + 2, 0);
	int* diagonalVisited = new int[(ll)N * 2 + 2];
	fill(xVisited, xVisited + N * 2 + 2, 0);
	cout << dfs(arr, 1, N, xVisited, diagonalVisited) << "\n";

	delete[] arr;

	return 0;
}