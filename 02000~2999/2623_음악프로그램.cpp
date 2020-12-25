/**
 *    BOJ 2623
 *    - 음악프로그램
 *    author:  phcdream
 *    created: 오후 7:54 2020-12-02
 */

#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

void in(int& N, int& M, vector<int>*& graph, int*& inDegree)
{
	cin >> N >> M;
	graph = new vector<int>[(ll)N + 1];
	inDegree = new int[(ll)N + 1];
	fill(inDegree, inDegree + N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		int prev = 0;
		if (n > 0)
			cin >> prev;
		for (int j = 1; j < n; j++)
		{
			int e;
			cin >> e;
			graph[prev].push_back(e);
			inDegree[e]++;
			prev = e;	// 추가
		}
	}
}

// 위상정렬(Topology Sort)
vector<int> solve(int N, vector<int>*& graph, int*& inDegree)
{
	vector<int> reVec;
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			reVec.push_back(i);
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
			inDegree[e]--;
			if (inDegree[e] == 0)
			{
				reVec.push_back(e);
				q.push(e);
			}
		}
	}

	// 사이클 확인
	bool isCycle = false;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] != 0)
		{
			isCycle = true;
			break;
		}
	}

	if (isCycle == true)
		return vector<int>{0};
	else
		return reVec;
}

void out(vector<int>& re)
{
	for (auto e : re)
		cout << e << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	vector<int>* graph;
	int* inDegree;
	in(N, M, graph, inDegree);

	vector<int> re = solve(N, graph, inDegree);
	out(re);

	return 0;
}

/*
6 3
3 1 4 3
4 6 2 5 4
2 2 3

1 1
1 1

2 2
2 1 2
2 2 1

3 1
1 1

3 1
2 1 2

3 2
2 1 2
2 2 3

3 2
3 1 2 3
2 2 3

3 2
2 2 1
2 2 1

5 3
2 1 2
2 1 3
3 2 5 3

5 2
3 1 2 3
2 4 2

*/