/**
 *    BOJ 1325
 *    - ȿ������ ��ŷ
 *    author:  phcdream
 *    created: ���� 3:41 2020-11-30
 */

 /*
 �ѱ� �ѱ� �����ٶ󸶹ٻ� �� �r �c��� ������ ���c���ϴ�
 */
#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

void in(int& N, int& M, vector<int>*& graph, int*& visited)
{
	cin >> N >> M;
	graph = new vector<int>[(ll)N + 1];
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[B].push_back(A);
	}
	visited = new int[(ll)N + 1];
	fill(visited, visited + N + 1, 0);
}

int dfs(int st, vector<int>*& graph, int*& visited)
{
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
			if (visited[e] == 0)
			{
				s.push(st);
				cnt++;
				visited[e] = 1;
				s.push(e);
			}
		}
	}
	return cnt;
}

vector<int> solve(int& N, vector<int>*& graph, int*& visited)
{
	int max = 0;
	int* re = new int[(ll)N + 1];
	for (int i = 1; i <= N; i++)
	{
		fill(visited, visited + N + 1, 0);
		int cnt = dfs(i,graph,visited);
		re[i] = cnt;
		max = cnt > max ? cnt : max;
	}
	vector<int> outVec;
	for (int i = 1; i <= N; i++)
		if (re[i] == max)
			outVec.push_back(i);

	return outVec;
}

void out(vector<int>& vec)
{
	for (auto e : vec)
		cout << e << " ";
	cout << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	vector<int>* graph;
	int* visited;
	in(N,M,graph,visited);

	vector<int> re = solve(N, graph, visited);
	out(re);

	return 0;
}