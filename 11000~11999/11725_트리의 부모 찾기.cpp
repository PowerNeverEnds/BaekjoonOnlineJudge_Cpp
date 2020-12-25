#include <iostream>
#include <vector>
#include <stack>
typedef long long ll;

using namespace std;

void dfs(int start, const vector<int>* graph, int* visited)
{
	stack<int> s;
	visited[start] = 0;
	s.push(start);
	while (true)
	{
		if (s.empty())
			break;
		start = s.top();
		s.pop();
		for (auto e : graph[start])
		{
			if (visited[e] == 0)
			{
				visited[e] = start;
				s.push(start);
				s.push(e);
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int>* graph = new vector<int>[(ll)N + 1];
	for (int i = 0; i < N-1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int* visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);

	dfs(1, graph, visited);
	
	for (int i = 2; i <= N; i++)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}