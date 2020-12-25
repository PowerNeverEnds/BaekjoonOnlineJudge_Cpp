#include <iostream>
#include <queue>
#include <vector>

#define U 0
#define W 1

typedef long long ll;

using namespace std;

// 12시 부터 반시계 방향
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
	int who;
};

int bfs(MyPoint st, char** arr, vector<MyPoint>& water, int** visited, MyPoint end)
{
	queue<MyPoint> q;
	// 물먼저 큐에 넣어서 물먼저움직이기
	for (auto e : water)
	{
		visited[e.y][e.x] = 1;
		q.push(e);
	}
	visited[st.y][st.x] = 1;
	q.push(st);

	while (true)
	{
		//for (int i = 1; i <= 3; i++)
		//{
		//	for (int j = 1; j <= 3; j++)
		//		cout << visited[i][j];
		//	cout << "\n";
		//}cout << "\n";
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] != 'X' && visited[nY][nX] == 0)
			{
				if (st.who == W && arr[nY][nX] == 'D')
					continue;
				visited[nY][nX] = visited[st.y][st.x] + 1;
				q.push(MyPoint({ nY,nX,st.who }));
				if (nY == end.y && nX == end.x && st.who == U)
				{
					return visited[nY][nX];
				}
			}
		}
	}

	return -1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int R, C;
	cin >> R >> C;

	char** arr = new char* [(ll)R + 2];
	fill(arr, arr + R + 2, nullptr);
	for (int i = 0; i < R + 2; i++)
	{
		arr[i] = new char[(ll)C + 2];
		fill(arr[i], arr[i] + C + 2, NULL);
	}
	fill(arr[0], arr[0] + C + 2, 'X');
	fill(arr[R + 2 - 1], arr[R + 2 - 1] + C + 2, 'X');
	for (int i = 0; i < R + 2; i++)
	{
		arr[i][0] = 'X';
		arr[i][C + 2 - 1] = 'X';
	}


	MyPoint st;
	MyPoint end;
	vector<MyPoint> water;
	st = MyPoint({ 0,0,U });
	end = MyPoint({ 0,0,U });
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				st.y = i;
				st.x = j;
			}
			if (arr[i][j] == 'D')
			{
				end.y = i;
				end.x = j;
			}
			if (arr[i][j] == '*')
			{
				water.push_back(MyPoint({ i,j,W }));
			}
		}
	}

	int** visited = new int* [(ll)R + 2];
	fill(visited, visited + R + 2, nullptr);
	for (int i = 0; i < R + 2; i++)
	{
		visited[i] = new int[(ll)C + 2];
		fill(visited[i], visited[i] + C + 2, 0);

	}

	if (bfs(st, arr, water, visited, end) == -1)
	{
		cout << "KAKTUS" << "\n";
	}
	else
	{
		cout << visited[end.y][end.x] - 1 << "\n";
	}



	return 0;
}