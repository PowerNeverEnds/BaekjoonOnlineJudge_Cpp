
#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;

using namespace std;

// 12시부터 반시계방향
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyStruct
{
	int y;
	int x;
};

int simul(int** arr, int** visited, queue<pair<int, char>>& qMove)
{
	int dir = 3;
	int tick = 0;
	pair<int, char> st;
	MyStruct snake{ 1,1 };
	bool run=true;
	MyStruct sTail{ 1,1 };
	visited[1][1] = 1;
	//cout << tick << "\n";
	//for (int i = 1; i <= 6; i++)
	//{
	//	for (int j = 1; j <= 6; j++)
	//	{
	//		cout << visited[i][j] << " ";
	//	}cout << "\n";
	//}cout << "\n";
	while (++tick)
	{
		//cout << tick << "\n";
		//cout << sTail.y << " " << sTail.x << "\n";
		if(!qMove.empty())
			st = qMove.front();
		int nY = snake.y + dy[dir];
		int nX = snake.x + dx[dir];
		if (arr[nY][nX] == 1)
		{
			arr[nY][nX] = 0;
			visited[nY][nX] = visited[snake.y][snake.x] + 1;
			snake.y = nY;
			snake.x = nX;
		}
		else if (arr[nY][nX] == -1 || visited[nY][nX] != 0)
		{
			break;
		}
		else
		{
			//cout << "Noting" << "\n";
			visited[nY][nX] = visited[snake.y][snake.x] + 1;
			snake.y = nY;
			snake.x = nX;
			for (int i = 0; i < 4; i++)
			{
				int nTY = sTail.y + dy[i];
				int nTX = sTail.x + dx[i];
				if (visited[nTY][nTX] == visited[sTail.y][sTail.x]+1)
				{
					visited[sTail.y][sTail.x] = 0;
					sTail.y = nTY;
					sTail.x = nTX;
					break;
				}
			}
		}
		if (st.first == tick)
		{
			//cout << "turn" << "\n";
			if (st.second == 'L')
				dir = (dir + 1) % 4;
			else if (st.second == 'D')
				dir = (dir - 1 + 4) % 4;
			qMove.pop();
		}
		//for (int i = 1; i <= 20; i++)
		//{
		//	for (int j = 1; j <= 20; j++)
		//	{
		//		cout << visited[i][j] << " ";
		//	}cout << "\n";
		//}cout << "\n";
		//tick++;
	}

	//for (int i = 1; i <= 6; i++)
	//{
	//	for (int j = 1; j <= 6; j++)
	//	{
	//		cout << visited[i][j] << " ";
	//	}cout << "\n";
	//}cout << "\n";
	return tick;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int K;
	cin >> K;

	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, 0);
	}

	fill(arr[0], arr[0] + N + 2, -1);
	fill(arr[N+2-1], arr[N+2-1] + N + 2, -1);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i][0] = -1;
		arr[i][N + 2 - 1] = -1;
	}

	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		arr[y][x] = 1;
	}

	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}

	queue<pair<int, char>> qMove;
	int L;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int X;
		char C;
		cin >> X >> C;
		qMove.push(make_pair(X, C));
	}


	cout << simul(arr, visited, qMove) << "\n";

	return 0;
}

