#include <iostream>
#include <queue>

#define INF (int)1e9

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

class MyClass
{
public:
	int y;
	int x;
	MyClass(int y = 0, int x = 0) :y(y), x(x) {};
	bool operator==(MyClass& B) {
		return (this->y == B.y && this->x == B.x);
	}
};

void bfs(MyClass start, int** arr, int** visited, int F, MyClass end)
{
	queue<MyClass> q;
	visited[start.y][start.x] = 0;
	q.push(start);

	while (true)
	{
		if (q.empty())
			break;

		start = q.front();
		q.pop();

		if (visited[start.y][start.x] >= F)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (visited[nY][nX] > visited[start.y][start.x] + 1)
			{
				// 이동할곳높이-현재위치높이<=(초기힘-사용한힘=남은힘)
				if (arr[nY][nX] - arr[start.y][start.x] <= F - visited[start.y][start.x])
				{
					visited[nY][nX] = visited[start.y][start.x] + 1;
					q.push(MyClass{ nY,nX });
					if (MyClass{ nY,nX } == end)
					{
						return;
					}
				}
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int H, W;
		cin >> H >> W;
		int O;
		cin >> O;
		int F, sY, sX, eY, eX;
		cin >> F >> sY >> sX >> eY >> eX;
		int** arr = new int* [(ll)H + 2];
		fill(arr, arr + H + 2, nullptr);
		for (int i = 0; i < H + 2; i++)
		{
			arr[i] = new int[(ll)W + 2];
			fill(arr[i], arr[i] + W + 2, 0);
		}

		// 방문(사용한힘)
		int** visited = new int* [(ll)H + 2];
		fill(visited, visited + H + 2, nullptr);
		for (int i = 0; i < H + 2; i++)
		{
			visited[i] = new int[(ll)W + 2];
			fill(visited[i], visited[i] + W + 2, INF);
		}

		// 가장자리
		for (int i = 0; i < H + 2; i++)
		{
			arr[i][0] = INF;
			arr[i][W + 2 - 1] = INF;
		}
		for (int i = 0; i < W + 2; i++)
		{
			arr[0][i] = INF;
			arr[H + 2 - 1][i] = INF;
		}

		// 장애물입력
		for (int o = 0; o < O; o++)
		{
			int Y, X, L;
			cin >> Y >> X >> L;
			arr[Y][X] = L;
		}

		MyClass start{ sY,sX };
		MyClass end{ eY,eX };
		bfs(start, arr, visited, F, end);

		if (visited[end.y][end.x] != INF)
			cout << "잘했어!!" << "\n";
		else
			cout << "인성 문제있어??" << "\n";
	}

	return 0;
}