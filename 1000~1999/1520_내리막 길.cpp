/**
 *    BOJ 1520
 *    - 내리막 길
 *    author:  phcdream
 *    created: 오후 9:14 2020-12-06
**/

#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
	int n;
	bool operator<(const MyPoint& mp)const {		//	less -> max-heap
		return n < mp.n;
	}
};

void in(int& N, int& M, int**& arr)
{
	cin >> N >> M;
	arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, -1);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
}

void print(int N, int M, int** visited)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << visited[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
}

void bfs(int N, int M, int**& arr, int**& visited)
{
	MyPoint st = MyPoint({ 1,1,arr[1][1] });
	priority_queue<MyPoint> pq;
	visited[st.y][st.x] = 1;
	pq.push(st);
	while (true)
	{
		if (pq.empty())
			break;
		st = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] != -1 && arr[st.y][st.x] > arr[nY][nX])
			{
				if (visited[nY][nX] == 0)
				{
					pq.push({ nY,nX,arr[nY][nX] });
				}
				visited[nY][nX] += visited[st.y][st.x];
			}

		}
	}
}

int solve(int N, int M, int**& arr)
{
	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, 0);
	}

	bfs(N, M, arr, visited);

	//print(N, M, visited);

	return visited[N][M];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;
	int** arr;
	in(N, M, arr);

	int re = solve(N, M, arr);
	cout << re << "\n";

	return 0;
}