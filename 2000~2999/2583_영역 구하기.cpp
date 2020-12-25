#include <iostream>
#include <stack>
#include <vector>
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

int dfs(MyStruct st, int** arr, int** visited)
{
	stack<MyStruct> s;
	visited[st.y][st.x] = 1;
	s.push(st);
	int cnt = 1;

	while (true)
	{
		if (s.empty())
			break;
		st = s.top();
		s.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] == 0 && visited[nY][nX] == 0)
			{
				s.push(st);
				cnt++;
				visited[nY][nX] = 1;
				s.push(MyStruct({ nY, nX }));
			}
		}
	}

	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N, K;
	cin >> M >> N >> K;

	int** arr = new int* [(ll)M + 2];
	fill(arr, arr + M + 2, nullptr);
	for (int i = 0; i < M + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, 0);
	}
	fill(arr[M + 2 - 1], arr[M + 2 - 1] + N + 2, 1);
	fill(arr[0], arr[0] + N + 2, 1);
	for (int i = 0; i < M + 2; i++)
	{
		arr[i][0] = 1;
		arr[i][N + 2 - 1] = 1;
	}

	for (int k = 0; k < K; k++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1 + 1; i <= y2; i++)
		{
			for (int j = x1 + 1; j <= x2; j++)
			{
				arr[i][j]++;
			}
		}
	}

	int** visited = new int* [(ll)M + 2];
	fill(visited, visited + M + 2, nullptr);
	for (int i = 0; i < M + 2; i++)
	{
		visited[i] = new int[(ll)N + 2];
		fill(visited[i], visited[i] + N + 2, 0);
	}

	vector<int> vec;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 0 && visited[i][j] == 0)
				vec.push_back(dfs(MyStruct({ i,j }), arr, visited));
		}

	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});

	cout << vec.size() << "\n";
	for (auto e : vec)
		cout << e << " ";
	cout << "\n";

	return 0;
}