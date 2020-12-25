/**
 *    BOJ 1043
 *    - °ÅÁþ¸»
 *    author:  phcdream
 *    created: ¿ÀÈÄ 6:13 2020-12-06
**/

#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

void in(int& N, int& M,int& t, bool*& visited, int**& arr, int*& tArr)
{
	cin >> N >> M;
	cin >> t;
	visited = new bool[(ll)N + 1];
	fill(visited, visited + N + 1, false);
	tArr = new int[(ll)t + 1];
	fill(tArr, tArr + t + 1, 0);
	for (int i = 1; i <= t; i++)
	{
		int e;
		cin >> e;
		visited[e] = true;
		tArr[i] = e;
	}
	arr = new int* [(ll)M + 1];
	fill(arr, arr + M + 1, nullptr);
	for (int i = 1; i <= M; i++)
	{
		int n;
		cin >> n;
		arr[i] = new int[(ll)n + 1];
		fill(arr[i], arr[i] + n + 1, 0);
		arr[i][0] = n;
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void dfs(int st, int N, int M, int t, bool*& visited, int**& arr, int*& tArr, vector<int>*& graph)
{
	stack<int> s;
	visited[st] = true;
	s.push(st);
	while (true)
	{
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		for (auto e : graph[st])
		{
			if (visited[e] == false)
			{
				s.push(st);
				visited[e] = true;
				s.push(e);
			}
		}
	}
}

int solve(int N, int M, int t, bool*& visited, int**& arr, int*& tArr)
{
	vector<int>* graph = new vector<int>[(ll)N + 1];
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= arr[i][0]-1; j++)
		{
			int u,v;
			u = arr[i][j];
			v = arr[i][j+1];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}
	for (int i = 1; i <= t; i++)
	{
		dfs(tArr[i], N, M, t, visited, arr, tArr, graph);
	}

	int cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		bool isOk = true;
		for (int j = 1; j <= arr[i][0]; j++)
		{
			if (visited[arr[i][j]] == true)
			{
				isOk = false;
				break;
			}
		}
		if (isOk == true)
			cnt++;
	}

	return cnt;
}

int main()
{
	int N, M;
	int t;
	bool* visited;
	int** arr;
	int* tArr;
	in(N, M,t, visited, arr, tArr);
	
	int re = solve(N, M, t, visited, arr, tArr);
	cout << re << "\n";

	delete[] visited;
	delete[] arr;
	delete[] tArr;

	return 0;
}

/*
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int* arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 0; i<=N;i++)
	{
		arr[i] = i;
	}
	int jinsiri;
	cin >> jinsiri;
	for (int i = 0; i < jinsiri; i++)
	{
		int e;
		cin >> e;
		arr[e] = 0;
	}

	vector<int>* party = new vector<int>[(ll)M];
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		int* tArr = new int[n];
		fill(tArr, tArr + n, 0);
		bool truth = false;
		for (int j = 0; j < n; j++)
		{
			cin >> tArr[j];
			party[i].push_back(tArr[j]);
			if (arr[tArr[j]] == 0)
				truth = true;
		}
		if (truth == true)
		{
			for (int j = 0; j < n; j++)
			{
				arr[tArr[j]] = 0;
			}
			for (int j=0;j<i;j++)
			{
				for(auto e:party[j])
				{

				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		bool truth = false;
		for (auto e : party[i])
		{
			if (arr[e] == 0)
			{
				truth = true;
				break;
			}
		}
		if (truth == true)
		{
		}
		else
			cnt++;
	}
	
	cout << cnt << "\n";

	return 0;
}
*/
/*
4 3
0
2 1 2
1 3
3 2 3 4

4 3
1
1
2 1 2
1 3
3 2 3 4

4 3
1
1
2 1 2
1 3
2 3 4

4 3
1
4
2 1 2
2 2 3
2 3 4

*/