/**
 *    BOJ 2668
 *    - ���ڰ���
 *    author:  phcdream
 *    created: ���� 6:36 2020-12-06
**/

#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

void in(int& N, vector<int>*& graph)
{
	cin >> N;
	graph = new vector<int>[(ll)N + 1];
	for (int i = 1; i <= N; i++)
	{
		int e;
		cin >> e;
		graph[i].push_back(e);
	}
}

int dfs(int st, vector<int>*& graph, int*& visited)
{
	int prev = st;
	int cnt = 0;
	stack<int> s;
	visited[st] = 1;
	s.push(st);
	while (true)
	{
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		for (auto e : graph[st])
		{
			if (visited[e] <= 1)
			{
				if (visited[e] == 1)
					cnt++;
				//s.push(st);		//	���ʿ� ������.d
				visited[e]++;
				s.push(e);
			}
		}
	}

	st = prev;
	if (visited[st] == 1)
	{
		visited[st] = 3;
		s.push(st);
		// �湮���ϰ�s
		while (true)
		{
			if (s.empty())
				break;
			st = s.top();
			s.pop();
			for (auto e : graph[st])
			{
				if (visited[e] == 1)	// ����Ŭ �ƴ� �ºκ�
				{
					//s.push(st);		//	���ʿ� ������.d
					visited[e] = 3;
					s.push(e);
				}
			}
		}
	}
	return cnt;
}
int solve(int N, vector<int>*& graph)
{
	int* visited = new int[(ll)N + 1];	// 0:�湮����, 1:�ѹ��湮->3:�������湮, 2: �ι��湮(����Ŭ)dd
	fill(visited, visited + N + 1, 0);
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int re=0;
		if(visited[i]==0)
			re = dfs(i, graph, visited);
		cnt += re;
	}

	cout << cnt << "\n";
	for (int i = 1; i <= N; i++)
	{
		//cout << i << " " << visited[i] << "\n";
		if (visited[i] == 2)
		{
			cout << i << "\n";
		}
	}

	return cnt;
}

int main()
{
	int N;
	vector<int>* graph;
	in(N, graph);

	solve(N, graph);

	return 0;
}