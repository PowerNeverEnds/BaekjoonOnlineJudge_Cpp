#include <iostream>
#include <stack>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};

void dfs(MyStruct start, int** arr, int** visited, int h)
{
	stack<MyStruct> s;
	visited[start.y][start.x] = 1;
	s.push(start);

	while (true)
	{
		if (s.empty())
			break;
		start = s.top();
		s.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (arr[nY][nX] > h && visited[nY][nX] == 0)
			{
				s.push(start);
				visited[nY][nX] = 1;
				s.push(MyStruct({ nY,nX }));
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < (ll)N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, 0);
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	int minH = 100;
	int maxH = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			minH = arr[i][j] < minH ? arr[i][j] : minH;
			maxH = arr[i][j] > maxH ? arr[i][j] : maxH;
		}
	minH = minH == 0 ? 0 + 1 : minH;
	//cout << minH << maxH;

	int max = 0;
	for (int h = minH - 1; h < maxH; h++)
	{
		int** visited = new int* [(ll)N + 2];
		fill(visited, visited + N + 2, nullptr);
		for (int i = 0; i < (ll)N + 2; i++)
		{
			visited[i] = new int[(ll)N + 2];
			fill(visited[i], visited[i] + N + 2, 0);
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] > h && visited[i][j] == 0)
				{
					dfs(MyStruct({ i,j }), arr, visited, h);
					cnt++;
				}
			}
		}
		//cout << h << " " << cnt << "\n";
		max = cnt > max ? cnt : max;
	}

	cout << max << "\n";

	return 0;
}