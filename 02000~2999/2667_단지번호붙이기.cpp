#include <iostream>
#include <string>
#include <algorithm>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};

void dfs(MyStruct start, int** arr, int** visited, int num)
{
	visited[start.y][start.x] = num;
	for (int i = 0; i < 4; i++)
	{
		int nY = start.y + dy[i];
		int nX = start.x + dx[i];
		if (arr[nY][nX] == 1 && visited[nY][nX] == 0)
		{
			dfs(MyStruct{ nY,nX }, arr, visited, num);
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
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, 0);
	}
	int** visited = new int* [(ll)N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (int j = 1; j <= N; j++)
			arr[i][j] = str[(ll)j - 1] - '0';
	}

	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 1 && visited[i][j] == 0)
			{
				num++;
				dfs(MyStruct{ i,j }, arr, visited, num);
			}
		}
	}
	int* count = new int[(ll)num + 1];
	fill(count, count + num + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			count[visited[i][j]]++;
		}
	}

	cout << num << "\n";
	sort(count + 1, count + num + 1, [](auto a, auto b) {
		return a < b;
		});
	for (int i = 1; i <= num; i++)
	{
		cout << count[i] << "\n";
	}


	return 0;
}