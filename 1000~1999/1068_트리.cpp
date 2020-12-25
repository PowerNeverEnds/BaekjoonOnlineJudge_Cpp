#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int dfs(vector<int>& root, vector<int>* graph, int del)
{
	int cnt = 0;
	stack<int> s;
	for (auto e : root)
	{
		if (graph[e].empty())
			continue;
		s.push(e);
	}
	int st;

	while (true)
	{
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		if (st == del)
			continue;
		if (graph[st].empty() || (graph[st].size() == 1 && graph[st].back() == del))
			cnt++;
		for (auto e : graph[st])
		{
			if (e == del)
			{
			}
			else
			{
				s.push(e);
			}
		}
	}
	return cnt;
}

int main()
{
	int N;
	cin >> N;

	vector<int>* graph = new vector<int>[(ll)N];
	vector<int> root;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		if (e == -1)
			root.push_back(i);
		else
			graph[e].push_back(i);
	}
	int del;
	cin >> del;

	cout << dfs(root, graph, del) << "\n";



	return 0;
}

/*
1
-1
0


3
-1 -1 -1
1

6
-1 -1 -1 0 1 2
3


7
-1 0 0 1 1 2 2
0

7
-1 0 0 1 1 2 2
3

4
-1 0 1 2
2


*/