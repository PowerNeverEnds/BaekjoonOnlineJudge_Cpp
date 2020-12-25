#include <iostream>

#define NO_CLEANING 5

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct MyStruct
{
	int y;
	int x;
};

int simul(MyStruct st, int** arr, int** visited, int d)
{
	int cnt = 0;
	visited[st.y][st.x] = d;
	cnt++;
	while (true)
	{
		//for (int i = 1; i <= 11; i++)
		//{
		//	for (int j = 1; j <= 10; j++)
		//	{
		//		if (arr[i][j] == 1)
		//			cout << "*" << " ";
		//		else
		//		cout << visited[i][j] << " ";
		//	}cout << "\n";
		//}cout << "\n";
		bool move = false;
		for (int i = 0; i < 4; i++)
		{
			int nD = (4 + visited[st.y][st.x] - 1) % 4;
			int nY = st.y + dy[nD];
			int nX = st.x + dx[nD];
			if (arr[nY][nX] == 0 && visited[nY][nX] == NO_CLEANING)
			{
				visited[nY][nX] = nD;
				st = MyStruct({ nY,nX });
				move = true;
				cnt++;
				break;
			}
			else
				visited[st.y][st.x] = nD;
		}
		//	4방향 탐색했는데 청소할 공간이 없는 경우
		if (move == false)
		{
			int nD = (4 + visited[st.y][st.x] - 2) % 4;	// -2: 180도 회전
			int nY = st.y + dy[nD];
			int nX = st.x + dx[nD];
			if (arr[nY][nX] == 0)
			{
				visited[nY][nX] = visited[st.y][st.x];
				st = MyStruct({ nY,nX });
			}
			else
			{
				break;
			}
		}
	}

	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, 1);
	}

	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, NO_CLEANING);
	}

	MyStruct start;
	cin >> start.y >> start.x;
	start.y += 1;
	start.x += 1;
	int d;
	cin >> d;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	cout << simul(start, arr, visited, d) << "\n";

	return 0;
}