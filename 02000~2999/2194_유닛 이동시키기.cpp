#include <iostream>
#include <queue>

#define INF 1e9

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};


int bfs(MyStruct start, int** arr, int** visited)
{
	queue<MyStruct> q;
	visited[start.y][start.x] = 0;
	q.push(start);

	while (true)
	{
		if (q.empty())
			break;
		start = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (visited[nY][nX] == INF)
			{
				if (arr[nY][nX] != 0)
				{
					if (arr[nY][nX] == 1)
						return visited[start.y][start.x] + 1;
				}
				else
				{
					visited[nY][nX] = visited[start.y][start.x] + 1;
					q.push(start);
					q.push(MyStruct{ nY,nX });
				}
			}

		}
	}
	return -1;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, A, B, K;
	cin >> N >> M >> A >> B >> K;

	// N*M ������ ���(1,1 ���ͽ���)
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, 0);
	}

	//	�ִܰŸ�
	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, INF);
	}

	//	������ ������� ��ġ��
	for (int i = 0; i < N + 2; i++)
	{
		arr[i][0] = -1;
		arr[i][M + 2 - 1] = -1;
	}
	for (int i = 0; i < M + 2; i++)
	{
		arr[0][i] = -1;
		arr[N + 2 - 1][i] = -1;
	}
	// ����ũ��-1 ��ŭ ���ø���(+�������ιб�)
	for (int j = 0; j < M + 2; j++)
		arr[(N + 2 - 1) - (A - 1)][j] = -1;
	for (int j = 0; j < N + 2; j++)
		arr[j][(M + 2 - 1) - (B - 1)] = -1;


	//	��ֹ� �Է¹ޱ�
	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;

		//	���η� A-1��ŭ�� ��ֹ��߰�
		for (int j = 0; j < A; j++)
		{
			if (y - j <= 0)	// 0�϶� ���ư��� �ȵ�.
				break;
			arr[y - j][x] = -1;
			if (0 < x - (B - 1))	// ��������
				arr[y - j][x - (B - 1)] = -1;
		}
		for (int j = 0; j < B; j++)
		{
			if (x - j <= 0)
				break;
			arr[y][x - j] = -1;
			if (0 < y - (A - 1))
				arr[y - (A - 1)][x - j] = -1;
		}
		arr[y][x] = -1;
	}

	int y, x;
	cin >> y >> x;
	MyStruct start{ y,x };


	//	�������� 1�� ǥ��
	cin >> y >> x;

	arr[y][x] = 1;

	int result = bfs(start, arr, visited);
	cout << result << "\n";

	return 0;
}

/*

#include <iostream>
#include <queue>

#define INF 1e9

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y;
	int x;
};


int bfs(MyStruct start, int** arr, int** visited)
{
	queue<MyStruct> q;
	visited[start.y][start.x] = 0;
	q.push(start);

	while (true)
	{
		if (q.empty())
			break;
		start = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = start.y + dy[i];
			int nX = start.x + dx[i];
			if (visited[nY][nX] == INF)
			{
				if (arr[nY][nX] != 0)
				{
					if (arr[nY][nX] == 1)
						return visited[start.y][start.x] + 1;
				}
				else
				{
					visited[nY][nX] = visited[start.y][start.x] + 1;
					q.push(start);
					q.push(MyStruct{ nY,nX });
				}
			}

		}
	}
	return -1;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, A, B, K;
	cin >> N >> M >> A >> B >> K;

	// N*M ������ ���(1,1 ���ͽ���)
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, 0);
	}

	//	�ִܰŸ�
	int** visited = new int* [(ll)N + 2];
	fill(visited, visited + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, INF);
	}

	//	������ ������� ��ġ��
	for (int i = 0; i < N + 2; i++)
	{
		arr[i][0] = -1;
		arr[i][M + 2 - 1] = -1;
	}
	for (int i = 0; i < M + 2; i++)
	{
		arr[0][i] = -1;
		arr[N + 2 - 1][i] = -1;
	}
	// ����ũ��-1 ��ŭ ���ø���(+�������ιб�)
	for (int j = 0; j < M + 2; j++)
		arr[(N + 2 - 1) - (A - 1)][j] = -1;
	for (int j = 0; j < N + 2; j++)
		arr[j][(M + 2 - 1) - (B - 1)] = -1;


	//	��ֹ� �Է¹ޱ�
	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;

		//	���η� A-1��ŭ�� ��ֹ��߰�
		for (int j = 0; j < A; j++)
		{
			if (y - j <= 0)	// 0�϶� ���ư��� �ȵ�.
				break;
			arr[y - j][x] = -1;
			if (0 < x - (B - 1))	// ��������
				arr[y - j][x - (B - 1)] = -1;
		}
		for (int j = 0; j < B; j++)
		{
			if (x - j <= 0)
				break;
			arr[y][x - j] = -1;
			if (0 < y - (A - 1))
				arr[y - (A - 1)][x - j] = -1;
		}
		arr[y][x] = -1;
	}

	int y, x;
	cin >> y >> x;
	MyStruct start{ y,x };


	//	�������� 1�� ǥ��
	cin >> y >> x;

	// ������ ���ľ� �ϱ⶧����, ��°Ŵ� �ƴ�, �Ʒ� �ּ� ���� ���
	//for (int j = 0; j < A; j++)
	//{
	//	if (y - j <= 0)	// 0�϶� ���ư��� �ȵ�.
	//		break;
	//	arr[y - j][x] = 1;
	//	if (0 < x - (B - 1))	// ��������
	//		arr[y - j][x - (B - 1)] = 1;
	//}
	//for (int j = 0; j < B; j++)
	//{
	//	if (x - j <= 0)
	//		break;
	//	arr[y][x - j] = 1;
	//	if (0 < y - (A - 1))
	//		arr[y - (A - 1)][x - j] = 1;
	//}
	arr[y][x] = 1;

	//for (int i = 0; i < N + 2; i++)
	//{
	//	for (int j = 0; j < M + 2; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}cout << "\n";
	//}

	int result = bfs(start, arr, visited);
	cout << result << "\n";

	//for (int i = 0; i < N + 2; i++)
	//{
	//	for (int j = 0; j < M + 2; j++)
	//	{
	//		cout << (visited[i][j] != INF ? visited[i][j]:0) << " ";
	//	}cout << "\n";
	//}

	return 0;
}

*/