#include <iostream>
#include <stack>

typedef long long ll;

using namespace std;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

struct MyStruct
{
	int y;
	int x;
};

void dfs(MyStruct start, int** arr, int** visited)
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
		for(int i=0;i<8;i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (arr[nY][nX] == 1 && visited[nY][nX] == 0)
			{
				s.push(start);
				visited[nY][nX] = 1;
				s.push(MyStruct{ nY,nX });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		int w, h;	// w너비: j가로, h높이: i세로
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		int** arr = new int*[(ll)h + 2];
		fill(arr, arr + h + 2, nullptr);
		for (int i = 0; i < h + 2; i++)
		{
			arr[i] = new int[(ll)w + 2];
			fill(arr[i], arr[i] + w + 2, 0);
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> arr[i][j];
			}
		}

		int** visited = new int* [(ll)h + 2];
		fill(visited, visited + h + 2, nullptr);
		for (int i = 0; i < h + 2; i++)
		{
			visited[i] = new int[(ll)w + 2];
			fill(visited[i], visited[i] + w + 2, 0);
		}

		int cnt = 0;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (arr[i][j]==1 && visited[i][j] == 0)
				{
					dfs(MyStruct{ i,j }, arr, visited);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}