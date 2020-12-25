/**
 *    BOJ 1005
 *    - ACM Craft
 *    author:  phcdream
 *    created: ¿ÀÈÄ 10:33 2020-12-10
**/

#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

void in(int& N, int& K, int*& weight, vector<int>*& graph, int*& inDegree, int& W)
{
	cin >> N >> K;
	weight = new int[(ll)N + 1];
	fill(weight, weight + N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i];
	}
	graph = new vector<int>[(ll)N + 1];
	inDegree = new int[(ll)N + 1];
	fill(inDegree, inDegree + N + 1, 0);
	for (int i = 0; i < K; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);		// graph[i] -> graph[u]
		inDegree[v]++;
	}
	cin >> W;
}

int solve(int& N, int& K, int*& weight, vector<int>*& graph, int*& inDegree, int& W)
{
	if (inDegree[W] == 0)
		return weight[W];
	int* visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			visited[i] = weight[i];
			q.push(i);
		}
	}
	int st;
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (auto e : graph[st])
		{
			if (visited[st] + weight[e] > visited[e])
			{
				visited[e] = visited[st] + weight[e];
			}
			inDegree[e]--;
			if (inDegree[e] == 0)
			{
				q.push(e);
				if (e == W)
					return visited[e];
			}
		}
	}
	delete[] visited;

	//return visited[W];
	return -1;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		int* weight;
		vector<int>* graph;
		int* inDegree;
		int W;
		in(N, K, weight, graph, inDegree, W);

		int re = solve(N, K, weight, graph, inDegree, W);
		cout << re << "\n";

		delete[] weight;
		delete[] graph;
		delete[] inDegree;
	}

	return 0;
}