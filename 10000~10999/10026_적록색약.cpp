#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int y;
	int x;
};

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

void dfs(MyStruct start, char** arr, bool** visited, char color)
{
	visited[start.y][start.x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nY = start.y + dy[i];
		int nX = start.x + dx[i];
		if (visited[nY][nX] == false && arr[nY][nX] == color)
		{
			visited[nY][nX] = true;
			dfs(MyStruct{ nY,nX }, arr, visited, color);
		}

	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	char** arr = new char* [(ll)N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new char[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, ' ');
	}


	for (int i = 1; i <= N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (int j = 1; j <= N; j++)
			arr[i][j] = str[(ll)j - 1];
	}
	for (int k = 0; k < 2; k++)
	{
		if (k == 1)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					if (arr[i][j] == 'G')
						arr[i][j] = 'R';

		bool** visited = new bool* [(ll)N + 2];
		fill(visited, visited + N + 2, nullptr);
		for (int i = 0; i < N + 2; i++)
		{
			visited[i] = new bool[(ll)N + 2];
			fill(visited[i], visited[i] + N + 2, false);
		}

		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visited[i][j] == true)
					continue;
				else
				{
					dfs(MyStruct{ i,j }, arr, visited, arr[i][j]);
					count++;
				}
			}
		}
		cout << count << " ";
	}
	cout << "\n";

	return 0;
}