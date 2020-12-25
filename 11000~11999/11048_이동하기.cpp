#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

int dy[3] = { 1,0,1 };
int dx[3] = { 0,1,1 };

struct MyStruct
{
	int y;
	int x;
};

void bfs(MyStruct start, int** arr, int** visited)
{
	queue<MyStruct> q;
	visited[start.y][start.x] = arr[start.y][start.x];
	q.push(start);
	while (true)
	{
		if (q.empty())
			break;
		start = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (arr[nY][nX] != -1)
			{
				if (arr[nY][nX] + visited[start.y][start.x] > visited[nY][nX])
				{
					visited[nY][nX] = arr[nY][nX] + visited[start.y][start.x];
					q.push(MyStruct({ nY,nX }));
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, -1);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, -1);
	}

	bfs(MyStruct({ 1,1 }), arr, visited);

	cout << visited[N][M] << "\n";

	return 0;
}