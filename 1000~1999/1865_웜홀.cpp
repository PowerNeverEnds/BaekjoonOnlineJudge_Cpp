/**
 BOJ 1865
 - ¿úÈ¦
 - ¿ÀÈÄ 6:01 2020-11-27
 */

#include <iostream>
#include <vector>

typedef long long ll;

#define INF ((int)1e9+7)

using namespace std;

struct MyStruct
{
	int n;
	int w;
};

void init(int& N, int& M, int& W, vector<MyStruct>*& graph, int*& visited)
{
	cin >> N >> M >> W;
	graph = new vector<MyStruct>[(ll)N + 1];
	for (int i = 0; i < M; i++)
	{
		int S, E, T;
		cin >> S >> E >> T;
		graph[S].push_back(MyStruct({ E,T }));
		graph[E].push_back(MyStruct({ S,T }));
	}
	for (int i = 0; i < W; i++)
	{
		int S, E, T;
		cin >> S >> E >> T;
		graph[S].push_back(MyStruct({ E,-T }));

	}
	visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, INF);
}

int solve(int& N, int& M, int& W, vector<MyStruct>* graph, int* visited)
{
	visited[1] = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto& e : graph[j])
			{
				if (visited[j] + e.w < visited[e.n])// && visited[j] != INF)
				{
					visited[e.n] = visited[j] + e.w;
				}
			}
		}
	}

	bool isCycle = false;
	for (int j = 1; j <= N; j++)
	{
		for (auto& e : graph[j])
		{
			if (visited[j] + e.w < visited[e.n])// && visited[j] != INF)
			{
				isCycle = true;
				break;
			}
		}
	}

	return isCycle;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC--)
	{
		int N, M, W;
		vector<MyStruct>* graph;
		int* visited;

		init(N, M, W, graph, visited);

		bool re = solve(N, M, W, graph, visited);

		if (re == true)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		delete[] graph;
		delete[] visited;
	}

	return 0;
}