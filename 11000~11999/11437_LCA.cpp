/**
 *    BOJ 11437
 *    - LCA
 *    author:  phcdream
 *    created: ¿ÀÀü 3:01 2020-12-16
**/

#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int pa;
	int d;
};

void bfs(int s, vector<int>*& graph, MyStruct*& visited)
{
	int st = s;
	queue<int> q;
	visited[st].d = 1;
	visited[st].pa = 0;
	q.push(st);
	while (true)
	{
		//cout << st << "\n";
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (auto e : graph[st])
		{
			if (visited[e].d == 0)
			{
				visited[e].d = visited[st].d + 1;
				visited[e].pa = st;
				q.push(e);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//	in
	int N;
	cin >> N;
	vector<int>* graph=new vector<int>[(ll)N+1];
	for (int i = 0; i < N-1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	MyStruct* visited = new MyStruct[(ll)N + 1];
	fill(visited, visited + N + 1, MyStruct{0,0});

	bfs(1,graph,visited);

	//cout << "M" << "\n";
	//	solve
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		while (true)
		{
			if (visited[u].d <= visited[v].d)
				break;
			u = visited[u].pa;
		}
		while (true)
		{
			if (visited[u].d >= visited[v].d)
				break;
			v = visited[v].pa;
		}
		while (true)
		{
			if (u==v)
				break;
			u = visited[u].pa;
			v = visited[v].pa;
		}

		cout << u << "\n";
	}

	return 0;
}

/*
15
1 2
1 3
2 4
3 7
6 2
3 8
4 9
2 5
5 11
7 13
10 4
11 15
12 5
14 7
6
6 11
10 9
2 6
7 6
8 13
8 15


*/