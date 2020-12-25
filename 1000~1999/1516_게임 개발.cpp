/**
 *    BOJ 1516
 *    - 게임 개발
 *    author:  phcdream
 *    created: 오전 1:54 2020-12-02
 */

#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

void in(int& N, vector<int>*& graph, int*& costArr, int*& inDegree)
{
	cin >> N;
	graph = new vector<int>[(ll)N + 1];
	costArr = new int[(ll)N + 1];
	fill(costArr, costArr + N + 1, 0);
	inDegree = new int[(ll)N + 1];
	fill(inDegree, inDegree + N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> costArr[i];
		while (true)
		{
			int n;
			cin >> n;
			if (n == -1)
				break;
			graph[n].push_back(i);
			inDegree[i]++;
		}
	}
}

int* solve(int N, vector<int>* graph, int* costArr, int* inDegree)
{
	int* sumArr;
	sumArr = new int[(ll)N + 1];
	fill(sumArr, sumArr + N + 1, 0);

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			sumArr[i] = costArr[i];
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
			if (sumArr[st] + costArr[e] > sumArr[e])
			{
				sumArr[e] = sumArr[st] + costArr[e];
			}
			inDegree[e]--;
			if (inDegree[e] == 0)
				q.push(e);
		}
	}

	return sumArr;
}

void out(int N, int* re)
{
	for (int i = 1; i <= N; i++)
		cout << re[i] << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	vector<int>* graph;
	int* inDegree;
	int* costArr;
	in(N, graph, costArr, inDegree);

	int* re = solve(N, graph, costArr, inDegree);
	out(N, re);

	return 0;
}