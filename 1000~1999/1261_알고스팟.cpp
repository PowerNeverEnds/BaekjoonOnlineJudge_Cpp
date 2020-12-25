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
};

void bfs(MyPoint st, int** arr, int** visited, MyPoint end)
{
	queue<MyPoint> q;
	queue<MyPoint> nextStep;
	visited[st.y][st.x] = 1;
	q.push(st);
	while (true)
	{
		if (q.empty() && nextStep.empty())
			break;

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
				if (arr[nY][nX] == 0 && visited[nY][nX] == 0)
				{
					visited[nY][nX] = visited[st.y][st.x];
					q.push(MyPoint({ nY,nX }));
					if (nY == end.y && nX == end.x)
						return;
				}
				else if (arr[nY][nX] == 1 && visited[nY][nX] == 0)
				{
					visited[nY][nX] = visited[st.y][st.x] + 1;
					nextStep.push(MyPoint({ nY,nX }));
				}
			}
		}
		while (true)
		{
			if (nextStep.empty())
				break;
			q.push(nextStep.front());
			nextStep.pop();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, -1);
	}
	
	char ch;
	for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> ch;
			arr[i][j] = ch - '0';
		}
	}

	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, 0);
	}

	bfs(MyPoint({ 1,1 }), arr, visited, MyPoint({ N,M }));

	cout << visited[N][M] - 1 << "\n";


	return 0;
}