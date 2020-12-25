#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int dfs(int st, vector<int>* graph, int* visited, int end)
{
	stack<int> s;
	visited[st] = 1;
	s.push(st);
	if (st == end)
		return visited[st];
	while (true)
	{
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		for (auto e : graph[st])
		{
			if (visited[e] == false)
			{
				visited[e] = visited[st] + 1;
				s.push(e);
				if (e == end)
					return visited[e];
			}
		}
	}

	//return -1;
	return 0;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int>* graph = new vector<int>[(ll)n + 1];
	//fill(graph, graph + n + 1, nullptr);
	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;	// u,v
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int* visited = new int[(ll)n + 1];
	fill(visited, visited + n + 1, 0);

	cout << dfs(a, graph, visited, b) - 1 << "\n";

	return 0;
}