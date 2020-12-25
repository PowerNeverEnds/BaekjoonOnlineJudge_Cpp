/**
 *    BOJ 1495
 *    - 기타리스트
 *    author:  phcdream
 *    created: 오전 4:24 2020-11-30
 */

#include <iostream>

typedef long long ll;

using namespace std;

void in(int& N, int& S, int& M, int*& arr, int**& visited)
{
	cin >> N >> S >> M;
	arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	visited = new int* [2];
	fill(visited, visited + 2, nullptr);
	for (int i = 0; i < 2; i++)
	{
		visited[i] = new int[(ll)M + 1];
	fill(visited[i], visited[i] + M + 1, 0);
	}
}

int solve(int N, int S, int M, int*& arr, int**& visited)
{
	visited[1][S] = 1;
	for (int i = 1; i <= N; i++)
	{
		bool isOk = false;
		for (int j = 0; j <= M; j++)
		{

			if (visited[i%2][j] == i)
			{
				bool bOper[2] = { 0 <= j - arr[i],j + arr[i] <= M };
				int oper[2] = { j - arr[i],j + arr[i] };
				for (int k = 0; k < 2; k++)
				{
					if (bOper[k] == true)
					{
						visited[!(i%2)][oper[k]] = i + 1;
						isOk = true;
					}
				}
			}
		}
		if (isOk == false)
			return -1;
	}

	//for (int i = 0; i <= M; i++)
	//	cout << visited[0][i] << " " << visited[1][i] << "\n";

	int max = 0;
	for (int i = 0; i <= M; i++)
		if (visited[!(N%2)][i] == N + 1)
			max = i;

	return max;
}
int main()
{
	int N, S, M;
	int* arr;
	int** visited;
	in(N, S, M, arr, visited);

	int re = solve(N, S, M, arr, visited);
	cout << re << "\n";

	return 0;
}