#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

bool bfs(int st, vector<int>* graph, int* visited)
{
	queue<int>q;
	visited[st] = 1;
	q.push(st);
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (auto e : graph[st])
		{
			if (visited[e] == 0)
			{
				visited[e] = -visited[st];
				q.push(e);
			}
			else
			{
				if (visited[e] == visited[st])
					return false;
			}
		}
	}

	return true;
}

int main()
{
	int K;
	cin >> K;
	while (K--)
	{
		int V, E;
		cin >> V >> E;
		vector<int>* graph = new vector<int>[(ll)V + 1];
		int u, v;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int* visited = new int[(ll)V + 1];
		fill(visited, visited + V + 1, 0);
		bool isBipartiteGraph = false;
		for (int i = 1; i <= V; i++)
		{
			if (visited[i] == 0)
				isBipartiteGraph = bfs(i, graph, visited);
			if (!isBipartiteGraph)
				break;
		}
		if (isBipartiteGraph)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		delete[]graph;
		delete[]visited;
	}

	return 0;
}