#include <iostream>
#include <queue>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

struct MyStruct
{
	int y = 0;
	int x = 0;
};

int dfs(MyStruct start, int** arr, int** visited)
{
	int cnt=0;
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
			//cout << start.y << " " << start.x << " ," << nY << " " << nX << "\n";
			if (arr[nY][nX] == 0 && visited[nY][nX] == 0)
			{
				s.push(start);
				visited[nY][nX] = visited[start.y][start.x] + 1;
				cnt++;
				s.push(MyStruct{ nY,nX });
			}
		}
	}
	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<MyStruct> virus;

	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < (ll)N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + (ll)M + 2, 0);
	}
	for (int i = 0; i < (ll)N + 2; i++)
	{
		arr[i][0] = 1;
		arr[i][(ll)M + 2 - 1] = 1;
	}
	fill(arr[0], arr[0] + M + 2, 1);
	fill(arr[N + 2 - 1], arr[N + 2 - 1] + M + 2, 1);
	
	int zeroCnt = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus.push_back(MyStruct{ i,j });
			if (arr[i][j] == 0)
				zeroCnt++;
		}
	//cout << zeroCnt << "\n";
	//for (int i = 0; i <= N + 1; i++)
	//{
	//	for (int j = 0; j <= M + 1; j++)
	//		cout << arr[i][j] << " ";
	//	cout << "\n";
	//}cout << "\n";
	MyStruct w, w2, w3;
	int min = 64;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 0 && w.y == 0)
			{
				w.y = i; w.x = j;
				arr[i][j] = 3;
			}
			else
				continue;
			int i2, j2;
			for ( i2 = 1; i2 <= N; i2++)
			{
				for ( j2 = 1; j2 <= M; j2++)
				{
					if (i2 == 1 && j2==1)
					{
						i2 = i;
						j2 = j;
					}
					if (arr[i2][j2] == 0 && w2.y == 0)
					{
						w2.y = i2; w2.x = j2;
						arr[i2][j2] = 3;
					}
					else
						continue;
					for (int i3 = 1; i3 <= N; i3++)
					{
						for (int j3 = 1; j3 <= M; j3++)
						{
							if (i3 == 1 && j3 == 1)
							{
								i3 = i2;
								j3 = j2;
							}
							if (arr[i3][j3] == 0 && w3.y == 0)
							{
								w3.y = i3; w3.x = j3;
								arr[i3][j3] = 3;
							}
							else
								continue;

							//for (int i = 0; i <= N + 1; i++)
							//{
							//	for (int j = 0; j <= M + 1; j++)
							//		cout << arr[i][j] << " ";
							//	cout << "\n";
							//}//cout << "\n";

							int** visited = new int* [(ll)N + 2];
							fill(visited, visited + N + 2, nullptr);
							for (int i = 0; i < (ll)N + 2; i++)
							{
								visited[i] = new int[(ll)M + 2];
								fill(visited[i], visited[i] + (ll)M + 2, 0);
							}
							int sum = 0;
							for (auto e : virus)
							{
								sum += dfs(e, arr, visited);
								//for (int i = 0; i <= N + 1; i++)
								//{
								//	for (int j = 0; j <= M + 1; j++)
								//		cout << visited[i][j] << " ";
								//	cout << "\n";
								//}cout << "\n";
								//cout << sum << "\n";
								if (min < sum)
									break;
							}
							min = sum < min ? sum : min;
							//cout << sum << " " << min << "\n";
							//cout << (ll)zeroCnt - min-3 << "\n";
							arr[w3.y][w3.x] = 0;
							w3.y = 0;
						}
					}

					arr[w2.y][w2.x] = 0;
					w2.y = 0;
				}
			}
			arr[w.y][w.x] = 0;
			w.y = 0;
		}
	}

	cout << (ll)zeroCnt - min-3 << "\n";

	return 0;
}