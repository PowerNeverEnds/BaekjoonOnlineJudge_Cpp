#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

// 반시계방향 + 앞뒤
int dy[6] = { -1,0,1,0,0,0 };
int dx[6] = { 0,-1,0,1,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };

struct MyPoint
{
	int y;
	int x;
	int h;
};

int bfs(vector<MyPoint>& vec, int*** arr, int*** visited)
{
	queue<MyPoint> q;
	for (auto e : vec)
	{
		visited[e.y][e.x][e.h] = 1;
		q.push(e);
	}
	MyPoint st = MyPoint({ 0,0,0 });
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			int nH = st.h + dh[i];
			if (arr[nY][nX][nH] == 0 && visited[nY][nX][nH] == 0)
			{
				visited[nY][nX][nH] = visited[st.y][st.x][st.h] + 1;
				q.push(MyPoint({ nY,nX,nH }));
			}
		}
	}
	return visited[st.y][st.x][st.h];
}

int main()
{

	int M, N, H;
	cin >> M >> N >> H;
	int*** arr = new int** [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int* [(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, nullptr);
		for (int j = 0; j < M + 2; j++)
		{
			arr[i][j] = new int[(ll)H + 2];
			fill(arr[i][j], arr[i][j] + H + 2, -1);
		}
	}

	for (int h = 1; h <= H; h++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> arr[i][j][h];
			}
		}
	}

	vector<MyPoint> vec;
	for (int h = 1; h <= H; h++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (arr[i][j][h] == 1)
					vec.push_back(MyPoint({ i,j,h }));
			}
		}
	}

	int*** visited = new int** [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int* [(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, nullptr);
		for (int j = 0; j < M + 2; j++)
		{
			visited[i][j] = new int[(ll)H + 2];
			fill(visited[i][j], visited[i][j] + H + 2, 0);
		}
	}
	int times = bfs(vec, arr, visited);

	bool noVisited = false;
	for (int h = 1; h <= H; h++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				//cout << visited[i][j][h] << " ";
				if (arr[i][j][h] == 0 && visited[i][j][h] == 0)
				{
					noVisited = true;
					break;
				}
			}
			//cout << "\n";
			if (noVisited == true)
				break;
		}
		//cout << "\n";
		if (noVisited == true)
			break;
	}
	//cout << "\n";
	if (noVisited == true)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << times - 1 << "\n";
	}

	return 0;
}