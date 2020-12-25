/**
 *    BOJ 13913
 *    - 숨바꼭질 4
 *    author:  phcdream
 *    created: 오전 6:29 2020-12-05
**/

#include <iostream>
#include <queue>
#include <stack>

typedef long long ll;

#define MAX ((int)1e5+7)

using namespace std;

void bfs(int N, int K, int*& visited, int*& prev)
{
	queue<int> q;
	visited[N] = 1;
	prev[N] = -1;
	q.push(N);
	int st;
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		bool bOper[3] = { 0 <= st - 1,st + 1 <= MAX,2 * st <= MAX };
		int oper[3] = { st - 1,st + 1,2 * st };
		for (int i = 0; i < 3; i++)
		{
			if (bOper[i] == true && visited[oper[i]] == 0)
			{
				visited[oper[i]] = visited[st] + 1;
				prev[oper[i]] = st;
				q.push(oper[i]);
				if (oper[i] == K)
				{
					return;
				}
			}
		}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	int* visited = new int[(ll)MAX + 1];
	fill(visited, visited + MAX + 1, 0);
	int* prev = new int[(ll)MAX + 1];
	fill(prev, prev + MAX + 1, -1);
	bfs(N, K, visited, prev);

	stack<int> s;
	int t = K;
	//for (int i = 0; i < 20; i++)
	//	cout <<i<<" "<< visited[i] << " " << prev[i] << "\n";
	while (true)
	{
		if (t == -1)
			break;
		s.push(t);
		t = prev[t];
	}

	cout << s.size() - 1 << "\n";
	while (true)
	{
		if (s.empty())
			break;
		cout << s.top() << " ";
		s.pop();
	}


	return 0;
}