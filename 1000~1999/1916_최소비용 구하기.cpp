#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

#define INF ((int)(1e9+7))

using namespace std;

struct MyStruct
{
	int v;
	int w;
	bool operator<(const MyStruct& ms) const {
		return w > ms.w;
	}
};

void dijkstra(MyStruct st, vector<MyStruct>* graph, int* visited, MyStruct end)
{
	priority_queue<MyStruct> pq;
	visited[st.v] = st.w;
	pq.push(st);
	while (true)
	{
		if (pq.empty())
			break;
		st = pq.top();
		pq.pop();
		if (visited[st.v] < st.w)
		{
			continue;
		}
		for (auto e : graph[st.v])
		{
			if (visited[e.v] > visited[st.v] + e.w)
			{
				visited[e.v] = visited[st.v] + e.w;
				pq.push(MyStruct({ e.v,visited[e.v] }));
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	vector<MyStruct>* graph = new vector<MyStruct>[(ll)N + 1];
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(MyStruct({ v,w }));
	}
	int st, end;
	cin >> st >> end;

	int* visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, INF);

	dijkstra(MyStruct({ st,0 }), graph, visited, MyStruct({ end,0 }));

	//for (int i = 1; i <= N; i++)
	//	cout << visited[i] << " ";
	//cout << "\n";

	cout << visited[end] << "\n";

	return 0;
}