/**
 *    BOJ 11060
 *    - 점프 점프
 *    author:  phcdream
 *    created: 오전 2:51 2020-12-06
**/

#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

void in(int& N, int*& arr)
{
	cin >> N;
	arr = new int[(ll)N];
	fill(arr, arr + N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

int bfs(int N, int* arr, int* visited)
{
	queue<int> q;
	int st = 0;
	visited[st] = 1;
	q.push(st);
	if (st == N - 1)
		return visited[st];
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 1; i <= arr[st]; i++)
		{
			int nX = i + st;
			if (nX >= N)
				break;
			if (visited[st] + 1 < visited[nX] || visited[nX] == 0)
			{
				visited[nX] = visited[st] + 1;
				q.push(nX);
				if (nX == N - 1)
					return visited[nX];
			}
		}
	}
	return -1;
}

int solve(int N, int* arr)
{
	int* visited = new int[(ll)N];
	fill(visited, visited + N, 0);

	int re = bfs(N, arr, visited);
	if (re == -1)
		return re;
	else
		return re - 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	in(N, arr);

	int re = solve(N, arr);
	cout << re << "\n";

	return 0;
}

/*
1
0

1
5

2
0 0

*/