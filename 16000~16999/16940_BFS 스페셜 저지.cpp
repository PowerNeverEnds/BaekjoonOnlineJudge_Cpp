#include <iostream>
#include <queue>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

void bfs(int start, const set<int>* graph, int* visited, queue<int>& in)
{
	queue<int> q;
	if (in.front() == 1)
	{
		in.pop();
	}
	visited[start] = 1;
	q.push(start);
	while (true)
	{
		if (q.empty())
			break;
		start = q.front();
		q.pop();

		while (true)
		{
			if (in.empty())
				break;
			if (graph[start].count(in.front()) != 1)
				break;
			if (visited[in.front()] == 0)
			{
				visited[in.front()] = visited[start] + 1;
				q.push(in.front());
				in.pop();
			}
			else
				break;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int* visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);

	set<int>* graph = new set<int>[(ll)N + 1];

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	queue<int> in;
	for (int i = 1; i <= N; i++)
	{
		int e;
		cin >> e;
		in.push(e);
	}

	bfs(1, graph, visited, in);
	if (in.size() == 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

	return 0;
}

/*

7

1 2

1 3

2 4

2 5

3 6

3 7

1 2 3 6 7 4 5

*/