#include <iostream>
#include <vector>
using namespace std;;

void dfs(int start, const vector<int>* graph, bool* visited)
{
	visited[start] = true;
	for (auto e : graph[start])
	{
		if (visited[e] == false)
		{
			dfs(e, graph, visited);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;
	vector<int>* graph = new vector<int>[(long long)N + 1];
	bool* visited = new bool[(long long)N + 1];
	fill(visited, visited + N + 1, false);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
		{
			count++;
			dfs(i, graph, visited);
		}
	}
	cout << count << "\n";


	return 0;
}