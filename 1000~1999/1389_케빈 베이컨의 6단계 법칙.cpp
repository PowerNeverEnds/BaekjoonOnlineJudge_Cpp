#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void bfs(int start, const vector<int>* graph, int* visited)
{
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		start = q.front();
		q.pop();
		for (auto e : graph[start])
		{
			if (visited[e] == 0)
			{
				visited[e] = visited[start] + 1;
				q.push(e);
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int>* graph = new vector<int>[(long long)N + 2];
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int user = 0;
	int num = -1;
	int* visited = new int[(long long)N + 2];
	for (int i = 1; i <= N; i++)
	{
		fill(visited, visited + N + 2, 0);
		bfs(i, graph,visited);
		int sum = 0;
		for (int j = 1; j <= N; j++)
		{
			sum += visited[j];
		}
		if (num > sum || num == -1)
		{
			user = i;
			num = sum;
		}
	}
	cout << user << "\n";


	return 0;
}