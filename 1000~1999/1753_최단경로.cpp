#include <iostream>
#include <vector>
#include <queue>

#define INF ((int)(1e9))

typedef long long ll;

using namespace std;

struct MyNode
{
	int n;	//	node
	int w;	//	weight

	bool operator<(const MyNode& ms) const {
		return w > ms.w;
	}
};

int* dijkstra(MyNode st, vector<MyNode>* graph, int V)
{
	priority_queue<MyNode> pq;
	int* d = new int[(ll)V + 1];
	fill(d, d + V + 1, INF);
	bool* visited = new bool[(ll)V + 1];
	fill(visited, visited + V + 1, false);
	d[st.n] = st.w;
	//visited[st] = true;
	pq.push(st);
	while (true)
	{
		if (pq.empty())
			break;
		st = pq.top();
		pq.pop();
		//if (visited[st.n] == false)
		//{
		//	if (st.w < d[st.n])
		//		d[st.n] = st.w;
		//}
		//else
		//	continue;
		//visited[st.n] = true;
		//for (auto e : graph[st.n])
		//{
		//	if (visited[e.n] == false)
		//	{
		//		//if (d[st] + e.w < d[e.n])
		//		//{
		//		//}
		//		MyNode t = MyNode({ e.n,e.w + st.w });
		//		pq.push(t);
		//	}
		//}


		if (st.w > d[st.n])
			continue;

		for (auto e : graph[st.n])
		{
			if (d[st.n] + e.w < d[e.n])
			{
				d[e.n] = d[st.n] + e.w;
				pq.push(MyNode{ e.n,d[e.n] });
			}
		}
	}
	//for (int i = 1; i <= V; i++)
	//	cout << d[i] << " ";
	//cout << "\n";

	return d;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;
	vector<MyNode>* graph = new vector<MyNode>[(ll)V+1];
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(MyNode({ v,w }));
		//graph[v].push_back(MyNode({ u,w }));
	}

	int* d = dijkstra(MyNode({ K,0 }), graph, V);
	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF)
			cout << "INF" << "\n";
		else
			cout << d[i] << "\n";
	}

	return 0;
}



/*
#include <iostream>
#include <vector>
#include <stack>

#define INF 1e9

typedef long long ll;

using namespace std;

struct MyStruct
{
	int node;
	int dist;
};

void dfs(int start, const vector<MyStruct>* graph, int* visited)
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
			int nDist = visited[start] + e.dist;
			if (nDist < visited[e.node])
			{
				visited[e.node] = nDist;
				s.push(start);
				s.push(e.node);
			}
		}

	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;
	vector<MyStruct>* graph = new vector<MyStruct>[(ll)V + 1];
	int* visited = new int[(ll)V + 1];
	fill(visited, visited + V + 1, INF);
	
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(MyStruct{ v,w });
	}

	dfs(K, graph, visited);

	for (int i = 1; i <= V; i++)
	{
		if (visited[i] == INF)
			cout << "INF" << "\n";
		else
			cout << visited[i] << "\n";
	}

	return 0;
}
*/