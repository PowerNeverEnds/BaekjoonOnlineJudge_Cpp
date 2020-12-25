#include <iostream>
#include <vector>
#include <stack>

#define INF 1e9+10

typedef long long ll;

using namespace std;

struct MyStruct
{
	int node;
	int dist;
};

MyStruct dfs(int n, const vector<MyStruct>* tree, int* visited)
{
	MyStruct max{ 0,0 };
	stack<int> s;
	visited[n] = 0;
	s.push(n);

	while (true)
	{
		if (s.empty())
			break;
		n = s.top();
		s.pop();
		for (int i = 0; i < tree[n].size(); i++)
		{
			if (visited[tree[n][i].node] == INF)
			{
				visited[tree[n][i].node] = visited[n] + tree[n][i].dist;
				if (max.dist < visited[tree[n][i].node])
				{
					max.dist = visited[tree[n][i].node];
					max.node = tree[n][i].node;
				}
				s.push(n);
				s.push(tree[n][i].node);
			}
		}
	}

	return max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V;
	cin >> V;
	
	vector<MyStruct>* tree = new vector<MyStruct>[V + 1];
	
	for (int i = 0; i < V; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < V; j++)
		{
			int node, dist;
			cin >> node;
			if (node == -1)
				break;
			else
			{
				cin >> dist;
				tree[n].push_back(MyStruct{ node, dist });
			}
		}
	}
	int* visited = new int[(ll)V + 1];
	fill(visited, visited + V + 1, INF);
	
	MyStruct max1 = dfs(1, tree, visited);

	fill(visited, visited + V + 1, INF);
	MyStruct max2 = dfs(max1.node, tree, visited);
	cout << max2.dist << "\n";
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <stack>

#define INF 1e9+10

typedef long long ll;

using namespace std;

struct MyStruct
{
	int node;
	int dist;
};

MyStruct dfs(int n, const vector<MyStruct>* tree, int* visited)
{
	MyStruct max{ 0,0 };
	stack<int> s;
	visited[n] = 0;
	s.push(n);

	while (true)
	{
		if (s.empty())
			break;
		//cout << s.top() << "\n";
		//for (int i = 0; i < 6; i++)
		//{
		//	cout << visited[i] << " ";
		//}cout << "\n\n";
		n = s.top();
		s.pop();
		//if (tree[n].size() == 1)
		//	s.pop();
		for (int i = 0; i < tree[n].size(); i++)
		{
			if (visited[tree[n][i].node] == INF)
			{
				visited[tree[n][i].node] = visited[n] + tree[n][i].dist;
				if (max.dist < visited[tree[n][i].node])
				{
					max.dist = visited[tree[n][i].node];
					max.node = tree[n][i].node;
				}
				s.push(n);
				s.push(tree[n][i].node);
			}
		}
		//s.push(n);
	}

	return max;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V;
	cin >> V;

	vector<MyStruct>* tree = new vector<MyStruct>[V + 1];

	for (int i = 0; i < V; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < V; j++)
		{
			int node, dist;
			cin >> node;
			if (node == -1)
				break;
			else
			{
				cin >> dist;
				tree[n].push_back(MyStruct{ node, dist });
			}
		}
	}
	int* visited = new int[(ll)V + 1];
	fill(visited, visited + V + 1, INF);

	MyStruct max1 = dfs(1, tree, visited);
	//cout << max1.node << " " << max1.dist << "\n";

	fill(visited, visited + V + 1, INF);
	MyStruct max2 = dfs(max1.node, tree, visited);
	//cout << max2.node << " " << max2.dist << "\n";
	cout << max2.dist << "\n";
	return 0;
}

*/