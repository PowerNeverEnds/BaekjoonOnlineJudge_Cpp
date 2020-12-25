#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int n;	//	node
	int w;	//	weight
};

MyStruct dfs(int st, vector<MyStruct>* tree, int* visited)
{
	MyStruct max = MyStruct({ 0,0 });
	stack<int> s;
	visited[st] = 0;
	s.push(st);
	while (true)
	{
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		for (auto e : tree[st])
		{
			if (visited[e.n] == -1)
			{
				s.push(st);
				visited[e.n] = visited[st] + e.w;
				s.push(e.n);
				if (visited[e.n] > max.w)
				{
					max.w = visited[e.n];
					max.n = e.n;
				}
			}
		}
	}
	return max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n;
	cin >> n;
	vector<MyStruct>* tree = new vector<MyStruct>[(ll)n + 1];
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back(MyStruct({ v,w }));
		tree[v].push_back(MyStruct({ u,w }));
	}

	int* visited = new int[(ll)n + 1];
	fill(visited, visited + n + 1, -1);
	MyStruct max = dfs(1, tree, visited);
	fill(visited, visited + n + 1, -1);
	max = dfs(max.n, tree, visited);

	cout << max.w << "\n";

	return 0;
}