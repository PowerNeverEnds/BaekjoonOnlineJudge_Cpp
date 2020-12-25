#include <iostream>
#include <stack>

typedef long long ll;

using namespace std;

void dfs(int st, int* arr, int* visited)
{
	int t = st;
	stack<int> s;
	visited[st] = 1;
	s.push(st);
	while (true)
	{
		//for (int i = 1; i <= 7; i++)
		//{
		//	cout << visited[i] << " ";
		//}cout << "\n";
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		int e = arr[st];
		if (visited[e] == -1)	// 이미 방문했지만 사이클을 이루지 않으면
			break;
		else if (visited[e] == 0)
		{
			//			s.push(st);	//필요없음
			visited[e] = 1;
			s.push(e);
		}
		else if (visited[e] == 1)	// 방문했는곳을 또 방문할경우(사이클이 되는경우)
		{
			visited[e] = 2;	// 2는 사이클이 되는 정점
			s.push(e);
		}
	}
	st = t;
	if (visited[st] != 2)	// 시작정점이 사이클이 안될경우
	{
		visited[st] = -1;
		s.push(st);
		while (true)	// 시작정점으로부터
		{
			if (s.empty())
				break;
			st = s.top();
			s.pop();
			int e;
			e = arr[st];
			if (visited[e] == 1)	// 사이클을 되지 않는 정점까지
			{
				visited[e] = -1;
				s.push(e);
			}
			else
				break;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int* arr = new int[(ll)n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		int* visited = new int[(ll)n + 1];
		fill(visited, visited + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				dfs(i, arr, visited);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] != 2)
				cnt++;
		}
		cout << cnt << "\n";



		delete[] arr;
		delete[] visited;
	}

	return 0;
}