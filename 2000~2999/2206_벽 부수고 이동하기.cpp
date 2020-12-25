#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

// 12시부터 반시계방향
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyStruct
{
	int y;
	int x;
	int w = 0;	// 1이면 벽을 부수고 이동했단 뜻
};

int bfs(MyStruct st, int** arr, int*** visited, MyStruct end)
{
	queue<MyStruct> q;
	visited[st.y][st.x][st.w] = 1;
	q.push(st);
	if (st.x == end.y && st.y == end.x)
	{
		return visited[st.x][st.y][st.w];
	}
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] != -1)
			{
				if (arr[nY][nX] == 1)
				{
					if (st.w == 0)
					{
						visited[nY][nX][1] = visited[st.y][st.x][0] + 1;
						q.push(MyStruct({ nY,nX,1 }));
					}
				}
				else if (arr[nY][nX] == 0)
				{
					if (visited[nY][nX][st.w] == 0)
					{
						visited[nY][nX][st.w] = visited[st.y][st.x][st.w] + 1;
						q.push(MyStruct({ nY,nX,st.w }));
						if (nY == end.y && nX == end.x)
						{
							return visited[nY][nX][st.w];
						}
					}
				}
			}
		}
		//for (int i = 1; i <= 6; i++)
		//{
		//	for (int j = 1; j <= 4; j++)
		//	{
		//		cout << visited[i][j][0];
		//	}
		//	cout << "\n";
		//}cout << "\n";
		//for (int i = 1; i <= 6; i++)
		//{
		//	for (int j = 1; j <= 4; j++)
		//	{
		//		cout << visited[i][j][1];
		//	}
		//	cout << "\n";
		//}cout << "\n";
		//cout << "\n";
	}

	return -1;
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
	{
		for (int j = 1; j <= M; j++)
		{
			char e;
			cin >> e;
			arr[i][j] = e - '0';
		}
	}

	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= M; j++)
	//	{
	//		cout << arr[i][j];
	//	}
	//	cout << "\n";
	//}

	// ijw 형식
	// 기존의 visited는 w= 0
	// 벽을 부수고 이동했으면 w1에 기록
	int*** visited = new int** [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int* [(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, nullptr);
		for (int j = 0; j < M + 2; j++)
		{
			visited[i][j] = new int[2];
			fill(visited[i][j], visited[i][j] + 2, 0);
		}
	}

	cout << bfs(MyStruct({ 1,1,0 }), arr, visited, MyStruct({ N,M })) << "\n";

	return 0;
}

/*
6 4
0000
1110
1000
0000
0111
0000

*/