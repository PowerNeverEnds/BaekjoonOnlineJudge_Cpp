#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

// 12왼쪽방향부터 반시계방향
int dy[8] = {
	-2,-1,1,2, 2,1,-1,-2
};
int dx[8] = {
	-1,-2,-2,-1,
	1,2,2,1
};

struct MyStruct
{
	int y;
	int x;
};

int bfs(MyStruct st, int** arr, int** visited, MyStruct end)
{
	queue<MyStruct> q;
	visited[st.y][st.x] = 1;
	q.push(st);
	if (q.front().y == end.y && q.front().x == end.x)
		return visited[st.y][st.x];
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] != -1 && visited[nY][nX] == 0)
			{
				visited[nY][nX] = visited[st.y][st.x] + 1;
				q.push(MyStruct({ nY,nX }));
				if (nY == end.y && nX == end.x)
					return visited[nY][nX];
			}
			//for (int i = 0 + 2; i < 8 + 2; i++)
			//{
			//	for (int j = 0 + 2; j < 8 + 2; j++)
			//	{
			//		cout << visited[i][j] << " ";
			//	}cout << "\n";
			//}cout << "\n";
		}
	}
	return -1;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int l;
		cin >> l;
		int sY, sX;
		cin >> sY >> sX;
		int eY, eX;
		cin >> eY >> eX;
		int** arr = new int* [(ll)l + 4];
		fill(arr, arr + l + 4, nullptr);
		for (int i = 0; i < l + 4; i++)
		{
			arr[i] = new int[(ll)l + 4];
			fill(arr[i], arr[i] + l + 4, 0);
		}
		fill(arr[0], arr[0] + l + 4, -1);
		fill(arr[1], arr[1] + l + 4, -1);
		fill(arr[l + 4 - 1], arr[l + 4 - 1] + l + 2, -1);
		fill(arr[l + 4 - 1 - 1], arr[l + 4 - 1 - 1] + l + 2, -1);
		for (int i = 0; i < l + 4; i++)
		{
			arr[i][0] = -1;
			arr[i][1] = -1;
			arr[i][l + 4 - 1] = -1;
			arr[i][l + 4 - 1 - 1] = -1;
		}

		int** visited = new int* [(ll)l + 4];
		fill(visited, visited + l + 4, nullptr);
		for (int i = 0; i < l + 4; i++)
		{
			visited[i] = new int[(ll)l + 4];
			fill(visited[i], visited[i] + l + 4, 0);
		}

		cout << bfs(MyStruct({ sY + 2,sX + 2 }), arr, visited, MyStruct({ eY + 2, eX + 2 })) - 1 << "\n";

		delete[] arr;
		delete[] visited;

	}
	return 0;
}