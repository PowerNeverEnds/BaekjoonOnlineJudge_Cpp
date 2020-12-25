#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};

void bfs(const vector<MyStruct>& tomato, int** arr, int** visited)
{

	queue<MyStruct> q;
	for (auto e : tomato)
	{
		q.push(e);
		visited[e.y][e.x] = 1;
	}

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = y + dy[i];
			int nX = x + dx[i];
			if (visited[nY][nX] == 0 && arr[nY][nX] != -1)
			{
				//주변에서 잴짧은시간찾기
				int min = INT_MAX;

				for (int j = 0; j < 4; j++)
				{
					int vY = nY + dy[j];
					int vX = nX + dx[j];
					if (visited[vY][vX] != 0)	// 이전에 방문한경우
						min = visited[vY][vX] < min ? visited[vY][vX] : min;
				}
				visited[nY][nX] = min + 1;
				q.push(MyStruct{ nY,nX });
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;		// M:가로, N:세로 가로세로 순서바뀜

	int** arr = new int* [(long long)N + 2];	// 토마토 
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(long long)M + 2];
		fill(arr[i], arr[i] + M + 2, -1);	// -1: 토마토가 들어있지않음 (1:익은토마토,0:익지않은토마토)
	}
	int** visited = new int* [(long long)N + 2];	// 토마토익은시간
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(long long)M + 2];
		fill(visited[i], visited[i] + M + 2, 0);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	//for (int i = 0; i < N + 2; i++)
	//{
	//	for (int j = 0; j < M + 2; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	vector<MyStruct> tomato;	// 토마토가있는위치(bfs시작시 큐에넣기위해서)
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 1)
			{
				tomato.push_back(MyStruct{ i,j });
			}
		}
	}
	bfs(tomato, arr, visited);

	//for (int i = 0; i < N + 2; i++)
	//{
	//	for (int j = 0; j < M + 2; j++)
	//	{
	//		cout << visited[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//
	int max = 0;
	for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j <=M; j++)
		{
			if (arr[i][j] != -1)
			{
				if (visited[i][j] == 0)		// 방문을못한토마토가 있는경우
				{
					cout << -1 << "\n";
					return 0;
				}
				max = visited[i][j] > max ? visited[i][j] : max;
			}
		}
	}
	cout << max - 1 << "\n";

	return 0;
}