#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

void dfs(int st, vector<int>* graph, int* visited)
{
	stack<int> s;
	visited[st] = 1;
	s.push(st);
	while (true)
	{
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		for (auto e : graph[st])
		{
			if (visited[e] == 0)
			{
				s.push(st);
				visited[e] = 1;
				s.push(e);
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int>* graph = new vector<int>[(ll)N + 1];
		for (int u = 1; u <= N; u++)
		{
			int v;
			cin >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int* visited = new int[(ll)N + 1];
		fill(visited, visited + N + 1, 0);

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0)
			{
				dfs(i,graph, visited);
				cnt++;
			}
		}

		cout << cnt << "\n";

		delete[] graph;
	}

	return 0;
}