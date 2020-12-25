/**
 *    BOJ 5567
 *    - °áÈ¥½Ä
 *    author:  phcdream
 *    created: ¿ÀÈÄ 9:18 2020-12-04
**/

#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

void in(int& n, int& m, vector<int>*& graph)
{
	cin >> n;
	cin >> m;
	graph = new vector<int>[(ll)n + 1];
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

int solve(int n, int m, vector<int>* graph)
{
	queue<int> q;
	int* visited = new int[(ll)n + 1];
	fill(visited, visited + n + 1, 0);
	int st = 1;
	visited[st] = 1;
	q.push(st);
	int cnt = 0;
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
				cnt++;
				visited[e] = visited[st] + 1;
				if (visited[e] == 2+1)
				{
				}
				else
				{
					q.push(e);
				}
			}
		}
	}

	return cnt;
}

int main()
{
	int n;
	int m;
	vector<int>* graph;
	in(n, m, graph);

	int re = solve(n, m, graph);
	cout << re << "\n";
	return 0;
}