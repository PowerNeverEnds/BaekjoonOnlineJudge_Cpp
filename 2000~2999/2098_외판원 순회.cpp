/**
 *    BOJ 2098
 *    - 외판원 순회
 *    author:  phcdream
 *    created: 오후 11:17 2020-12-11
**/

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

struct MyNode
{
	int n;
	int w;
};

void in(int& N, vector<MyNode>*& graph)
{
	cin >> N;
	graph = new vector<MyNode>[(ll)N + 1];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int e;
			cin >> e;
			if (e != 0)
			{
				graph[i].push_back({ j,e });
			}
		}
	}
}

void dfs(int& N, vector<MyNode>*& graph,int s, int**& visited)
{
	//for (auto e : graph[s])
	//{
	//	nS=
	//	if(visited[s][e])
	//}

}

void solve(int& N, vector<MyNode>*& graph)
{
	int** visited = new int* [(ll)N + 1];
	fill(visited, visited + N + 1, nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		visited[i] = new int[(ll)1 << N];
		fill(visited[i], visited[i] + ((ll)1 << N), 0);
	}
	//cout << (1 << N) << "\n";
	for (int i = 1; i <= N; i++)
	{
		dfs(N, graph,i, visited);
	}
}

int main()
{
	int N;
	vector<MyNode>* graph;
	in(N, graph);

	solve(N, graph);

	return 0;
}