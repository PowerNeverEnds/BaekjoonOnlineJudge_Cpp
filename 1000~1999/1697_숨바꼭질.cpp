#include <iostream>
#include <queue>
using namespace std;

void bfs(int N, const int K, int* visited)
{
	queue<int> q;
	visited[N] = 0;
	q.push(N);
	while (true)
	{
		N = q.front();
		q.pop();
		if (N == K)
		{
			break;
		}
		if (0 + 1 <= N)		// -1 Ä­ÀÌµ¿(ÁÂÇ¥°¡1ÀÌ»óÀÏ¶§¸¸ÀÌµ¿)
		{
			if (visited[N - 1] > visited[N] + 1 || visited[N - 1] == -1)
			{
				visited[N - 1] = visited[N] + 1;
				q.push(N - 1);
			}
		}
		if (N<=200000 - 1)		// +1Ä­ÀÌµ¿
		{
			if (visited[N + 1] > visited[N] + 1 || visited[N + 1] == -1)
			{
				visited[N + 1] = visited[N] + 1;
				q.push(N + 1);
			}
		}
		if (N <= 100000)
		{
			if (visited[N * 2] > visited[N] + 1 || visited[N * 2] == -1)
			{
				visited[N * 2] = visited[N] + 1;
				q.push(N * 2);
			}
		}
	}
}
int visited[200001] = { 0, };
int main()
{
	int N, K;
	cin >> N >> K;
	fill(visited, visited + 200001, -1);
	
	bfs(N, K, visited);

	cout << visited[K] << "\n";

	return 0;
}