#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int V, const vector<int>* graph, bool* visited)
{
	visited[V] = true;
	cout << V << " ";
	for (auto e : graph[V])
	{
		if (visited[e] == false)
		{
			dfs(e, graph, visited);
		}
	}
}

void bfs(int V, const vector<int>* graph, bool* visited)
{
	visited[V] = true;
	queue<int> q;
	q.push(V);
	while (!q.empty())
	{
		V = q.front();
		q.pop();
		cout << V << " ";
		for (auto e : graph[V])
		{
			if (visited[e] == false)
			{
				q.push(e);
				visited[e] = true;
			}
		}
	}


}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int N, M, V;
	cin >> N >> M >> V;

	vector<int>* graph = new vector<int>[(long long)N + 1];

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end(), [](auto a, auto b) {
			return a < b;
			});
	}

	bool* visited = new bool[(long long)N + 1]();
	fill(visited, visited + N + 1, false);
	dfs(V, graph, visited);
	cout << "\n";

	fill(visited, visited + N + 1, false);
	bfs(V, graph, visited);


	return 0;
}