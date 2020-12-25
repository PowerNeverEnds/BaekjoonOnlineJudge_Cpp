/*
같은 코드, 주석만 지운것.
*/


/*
#include <iostream>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};

int distDef(MyStruct a, MyStruct b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

int bfs(MyStruct start, int** arr, int** visited,int N,int size, MyStruct& end, int depth=0)
{
	queue<MyStruct> q;
	visited[start.y][start.x] = 1;
	q.push(start);
	int dSum = 0;
	while (!q.empty())
	{
		start = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (arr[nY][nX] <= size && (visited[nY][nX] == 0 && arr[nY][nX]!=-1))
			{
				//cout <<visited[start.y][start.x]<<": "<<start.y<<" "<<start.x<<", "<<nY<<" "<<nX<<" "<< depth << "\n";
				if (depth != 0 && depth != visited[start.y][start.x])
				{
					return depth;
				}
				visited[nY][nX] = visited[start.y][start.x] + 1;
				if (arr[nY][nX] < size && arr[nY][nX]>0)
				{
					if (end.y > nY)
					{
						end.y = nY;
						end.x = nX;
						depth = visited[start.y][start.x];
					}
					else if (end.y == nY && end.x > nX)
					{
						end.y = nY;
						end.x = nX;
						depth = visited[start.y][start.x];
					}
				}
				//				visited[nY][nX] = visited[start.y][start.x] + 1;
				//cout << "v" << "\n";
				//for (int i = 0; i < N + 2; i++)
				//{
				//	for (int j = 0; j < N + 2; j++)
				//	{
				//		cout << visited[i][j] << " ";
				//	}
				//	cout << "\n";
				//}
				q.push(MyStruct{ nY,nX });
			}
		}
		
	}
	return depth;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, -1);
	}
	MyStruct start{ 0,0 };
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				start.y = i;
				start.x = j;
			}
		}
	}
	int** visited = new int*[(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}
	int size = 2;
	int food = 0;
	int sec = 0;
	arr[start.y][start.x] = 0;
	while (true)
	{
		MyStruct end{ N+1 ,N+1 };
		int result = bfs(start, arr, visited,N, size, end);
		//for (int i = 0; i < N + 2; i++)
		//{
		//	for (int j = 0; j < N + 2; j++)
		//	{
		//		cout << visited[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//for (int i = 0; i < N + 2; i++)
		//{
		//	for (int j = 0; j < N + 2; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		if (result)
		{
			arr[end.y][end.x] = 0;
			start.y = end.y;
			start.x = end.x;
			sec += result;
			food++;
			if (food == size)
			{
				size++;
				food = 0;
			}
				for (int i = 0; i < N + 2; i++)
				{
					fill(visited[i], visited[i] + N + 2, 0);
				}
		}
		else
			break;
		//for (int i = 0; i < N + 2; i++)
		//{
		//	for (int j = 0; j < N + 2; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

	}
	cout << sec << "\n";

	return 0;
}
*/
/*
7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

*/



#include <iostream>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};

int distDef(MyStruct a, MyStruct b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

int bfs(MyStruct start, int** arr, int** visited,int N,int size, MyStruct& end, int depth=0)
{
	queue<MyStruct> q;
	visited[start.y][start.x] = 1;
	q.push(start);
	int dSum = 0;
	while (!q.empty())
	{
		start = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (arr[nY][nX] <= size && (visited[nY][nX] == 0 && arr[nY][nX]!=-1))
			{
				if (depth != 0 && depth != visited[start.y][start.x])
				{
					return depth;
				}
				visited[nY][nX] = visited[start.y][start.x] + 1;
				if (arr[nY][nX] < size && arr[nY][nX]>0)
				{
					if (end.y > nY)
					{
						end.y = nY;
						end.x = nX;
						depth = visited[start.y][start.x];
					}
					else if (end.y == nY && end.x > nX)
					{
						end.y = nY;
						end.x = nX;
						depth = visited[start.y][start.x];
					}
				}
				q.push(MyStruct{ nY,nX });
			}
		}

	}
	return depth;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, -1);
	}
	MyStruct start{ 0,0 };
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				start.y = i;
				start.x = j;
			}
		}
	}
	int** visited = new int*[(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}
	int size = 2;
	int food = 0;
	int sec = 0;
	arr[start.y][start.x] = 0;
	while (true)
	{
		MyStruct end{ N+1 ,N+1 };
		int result = bfs(start, arr, visited,N, size, end);
		if (result)
		{
			arr[end.y][end.x] = 0;
			start.y = end.y;
			start.x = end.x;
			sec += result;
			food++;
			if (food == size)
			{
				size++;
				food = 0;
			}
				for (int i = 0; i < N + 2; i++)
				{
					fill(visited[i], visited[i] + N + 2, 0);
				}
		}
		else
			break;

	}
	cout << sec << "\n";

	return 0;
}
