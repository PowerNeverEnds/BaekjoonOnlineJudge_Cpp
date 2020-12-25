/**
 *    BOJ 2458
 *    - 키 순서
 *    author:  phcdream
 *    created: 오전 4:20 2020-12-06
**/

#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

void in(int& N, int& M, vector<int>*& graph, vector<int>*& revGraph)
{
	cin >> N >> M;
	graph = new vector<int>[(ll)N + 1];
	revGraph = new vector<int>[(ll)N + 1];
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		revGraph[b].push_back(a);
	}
}

void dfs(const int i, vector<int>*& graph, int*& visited)
{
	int st = i;
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

int solve(int& N, int& M, vector<int>*& graph, vector<int>*& revGraph)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int* visited = new int[(ll)N + 1];
		fill(visited, visited + N + 1, 0);

		dfs(i,graph,visited);
		dfs(i, revGraph, visited);

		bool allTrue = true;
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == false)
			{
				allTrue = false;
				break;
			}
		}
		if (allTrue == true)
		{
			cnt++;
		}
		delete[] visited;
	}

	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	vector<int>* graph;
	vector<int>* revGraph;
	in(N, M, graph, revGraph);

	int re = solve(N, M, graph, revGraph);
	cout << re << "\n";

	return 0;
}