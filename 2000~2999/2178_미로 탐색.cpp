#include <iostream>
#include <vector>
#include <queue>
#include <string>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};

void bfs(MyStruct start,MyStruct end, int** arr, int** visited)
{
	queue<MyStruct> q;
	visited[start.y][start.x] = 1;
	q.push(start);
	while (true)
	{
		start = q.front();
		q.pop();
		if(start.y == end.y && start.x == end.x)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];

			if (arr[nY][nX] == 1 && visited[nY][nX]==0)
			{
				visited[nY][nX] = visited[start.y][start.x] + 1;
				q.push(MyStruct{ nY,nX });
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
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, 0);
	}

	int** visited = new int* [(ll)N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		cin.ignore();
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++)
			arr[i][j] = str[(ll)j - 1] - '0';
	}

	//for (int i = 0; i < N + 2; i++)
	//{
	//	for (int j = 0; j < M + 2; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	bfs(MyStruct{ 1,1 }, MyStruct{ N,M }, arr, visited);
	
	cout << visited[N][M] << "\n";

	return 0;
}