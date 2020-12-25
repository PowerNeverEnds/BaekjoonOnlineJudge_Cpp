/**
 BOJ 2631
 - 줄세우기
 - 오전 12:57 2020-11-28
 */

#include <iostream>

typedef long long ll;

using namespace std;

void init(int& N, int*& arr, int*& visited)
{
	cin >> N;
	arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);

}

int solve(int& N, int*& arr, int*& visited)
{
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		visited[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i])
			{
				if (visited[j] + 1 > visited[i])
				{
					visited[i] = visited[j] + 1;
				}
			}
		}
		max = visited[i] > max ? visited[i] : max;
	}

	return max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	int* visited;
	init(N, arr, visited);

	int re = solve(N, arr, visited);

	cout << N - re << "\n";

	return 0;
}