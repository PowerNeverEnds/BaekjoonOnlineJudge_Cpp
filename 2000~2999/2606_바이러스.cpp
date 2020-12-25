#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, const vector<int>* graph, bool* visited)
{
	visited[v] = true;
	for (auto e : graph[v])
	{
		if (visited[e] == false)
			dfs(e, graph, visited);
	}
}
int main()
{
	int n, m;
	cin >> n;
	vector<int>* graph = new vector<int>[n + 1];
	bool* visited = new bool[(long long)n + 1]();
	cin >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, graph, visited);

	int c = 0;
	for (int i = 2; i <= n; i++)
	{
		c += (visited[i] == true ? 1 : 0);
	}
	cout << c << "\n";

	return 0;
}