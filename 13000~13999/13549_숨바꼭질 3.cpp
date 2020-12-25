#include <iostream>
#include <queue>

typedef long long ll;

#define MAX 200001

using namespace std;

void qPush2X(int st, queue<int>& q, int* visited)
{
	if (st == 0)
		return;
	else
		while (true)
		{
			if (st * 2 > MAX)
				break;
			if (visited[st * 2] > visited[st])
				visited[st * 2] = visited[st];
			else
				break;
			q.push(st);
			st *= 2;
		}
}

int bfs(int st, int end, int* visited)
{
	queue<int> q;
	visited[st] = 1;
	q.push(st);
	//if (st == end)
	//	return visited[st];
	qPush2X(st, q, visited);
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		if (st == end)
			return visited[st];
		if (0 <= st && st <= MAX)
		{
			if (0 < st && visited[st - 1] > visited[st] + 1)
			{
				visited[st - 1] = visited[st] + 1;
				q.push(st - 1);
				qPush2X(st - 1, q, visited);
			}
			if (st<MAX && visited[st + 1]>visited[st] + 1)
			{
				visited[st + 1] = visited[st] + 1;
				q.push(st + 1);
				qPush2X(st + 1, q, visited);
			}
		}
	}
	return -1;
}

int main()
{
	int N, K;
	cin >> N >> K;
	int* visited = new int[(ll)MAX];
	fill(visited, visited + MAX, MAX);
	//	int visited[MAX] = { 0, };
	cout << bfs(N, K, visited) - 1 << "\n";

	return 0;
}