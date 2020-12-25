#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

#define INF ((int)1e8+7)

using namespace std;

struct MyStruct
{
	int n;
	int w;
	bool operator<(const MyStruct& ms) const {
		return w > ms.w;
	}
};

void dijkstra(MyStruct st, vector<MyStruct>* graph, MyStruct* visited, int end)
{
	priority_queue<MyStruct> pq;
	visited[st.n] = MyStruct({ 0,st.w });
	pq.push(st);
	while (true)
	{
		if (pq.empty())
			break;
		st = pq.top();
		pq.pop();
		if (st.w > visited[st.n].w)
			continue;
		for (auto e : graph[st.n])
		{
			if (visited[e.n].w > st.w + e.w)
			{
				visited[e.n].w = st.w + e.w;
				visited[e.n].n = st.n;
				pq.push(MyStruct({ e.n,visited[e.n].w }));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<MyStruct>* graph = new vector<MyStruct>[(ll)n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(MyStruct({ v,w }));
	}

	MyStruct* visited = new MyStruct[(ll)n + 1];
	fill(visited, visited + n + 1, MyStruct({ 0,INF }));


	int st, end;
	cin >> st >> end;
	//cout << "go dijkstra!" << "\n";
	dijkstra(MyStruct({ st,0 }), graph, visited, end);

	vector<int> path;
	int t = end;
	while (true)
	{
		//cout << t << "\n";
		path.push_back(t);
		if (t == st)
			break;
		t = visited[t].n;
	}
	cout << visited[end].w << "\n";
	cout << path.size() << "\n";
	for (auto e = path.rbegin(); e != path.rend(); e++)
	{
		cout << *e << " ";
	}cout << "\n";

	return 0;
}