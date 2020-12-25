#include <iostream>

typedef long long ll;

using namespace std;

struct DisJointSet
{
	int* root;
	void disJointSet(int n)
	{
		root = new int[(ll)n + 1];
		fill(root, root + n + 1, 0);
		for (int i = 0; i <= n; i++)
			root[i] = i;
	}
	int disJointSet_Find(int a)
	{
		if (root[a] == a)
			return a;
		else
			return root[a] = disJointSet_Find(root[a]);
	}
	void disJointSet_Union(int a, int b)
	{
		a = disJointSet_Find(a);
		b = disJointSet_Find(b);

		root[b] = a;

		//if (disJointSet_Find(a) == disJointSet_Find(b))
		//{
		//}
		//else
		//{
		//	root[a] = root[b];
		//}
	}

};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	DisJointSet djs;
	djs.disJointSet(n);


	for (int i = 0; i < m; i++)
	{
		int o, a, b;
		cin >> o >> a >> b;
		if (o == 0)
		{
			djs.disJointSet_Union(a, b);
		}
		else
		{
			if (djs.disJointSet_Find(a) == djs.disJointSet_Find(b))
			{
				cout << "YES" << "\n";
			}
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}



/*
#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int dfs(int start, const vector<int>* graph, int* visited, int b)
{
	stack<int> s;
	visited[start] = 1;
	s.push(start);

	while (true)
	{
		if (s.empty())
			break;
		start = s.top();
		s.pop();
		if (start == b)
			return true;
		for (auto e : graph[start])
		{
			if (visited[e] == 0)
			{
				s.push(start);
				visited[e] = 1;
				s.push(e);
			}
		}
	}

	return false;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int>* graph = new vector<int>[(ll)n + 1];

	for (int i = 0; i < m; i++)
	{
		int o, a, b;
		cin >> o >> a >> b;
		if (o == 0)
		{
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		else
		{
			bool sameSet = false;
			int* visited = new int[(ll)n + 1];
			fill(visited, visited + n + 1, 0);
			sameSet=dfs(a, graph, visited, b);
			if (sameSet == 1)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";

			delete[] visited;
		}
	}

	return 0;
}
*/