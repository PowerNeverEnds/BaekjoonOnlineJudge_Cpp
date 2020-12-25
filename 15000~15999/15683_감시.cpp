/**
 *    BOJ 15683
 *    - 감시
 *    author:  phcdream
 *    created: 오전 1:49 2020-12-05
**/

#include <iostream>
#include <vector>

typedef long long ll;

#define WALL 6
#define INF ((int)1e2)
using namespace std;

struct MyPoint
{
	int y;
	int x;
};

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

int cctv[6][4] = { {},
	{1,0,0,0},
	{1,0,1,0},
	{1,1,0,0},
	{1,1,1,0},
	{1,1,1,1}
};

void in(int& N, int& M, int**& arr)
{
	cin >> N >> M;
	arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)M + 2];
		fill(arr[i], arr[i] + M + 2, WALL);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
}

void setVisited(int N, int M, int** arr, MyPoint e, int**& visited, int dir)
{
	int cctvNum = arr[e.y][e.x];
	for (int i = 0; i < 4; i++)
	{
		int d = (i + dir) % 4;
		//cout <<i<<" "<<dir<<" d "<< d <<" "<<dy[d]<<" "<<dx[d]<< "\n";
		if (cctv[cctvNum][(i + dir) % 4] == 1)
		{
			//cout << i << " " << dir << "\n";
			for (int k = 1;; k++)
			{
				int nY = e.y + dy[i] * k;
				int nX = e.x + dx[i] * k;
				if (arr[nY][nX] ==WALL)	//!=0 에서 ==WALL로 변경(CCTV끼리는 관통가능)
				{
					break;
				}
				else
				{
					visited[nY][nX] = cctvNum;
				}
			}
		}
	}
}

int simul(int N, int M, int** arr, int** visited, int depth, int size, vector<MyPoint> vec, int*& vVisited)
{
	for (int i = 1; i < size; i++)
	{
		auto e = vec[i];
		setVisited(N, M, arr, e, visited, vVisited[i]);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 0 && visited[i][j] == 0)
			{
				cnt++;
			}
		}

	}
	//cout << "\n";
	//for (int i = 1; i < vec.size(); i++)
	//{
	//	cout << vVisited[i] << " ";
	//}cout << "\n";
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= M; j++)
	//	{
	//		cout << visited[i][j] << " ";
	//	}cout << "\n";
	//}cout << "\n";

	return cnt;
}
int dfs(int N, int M, int** arr, int**& visited, int depth, int size, vector<MyPoint> vec, int*& vVisited)
{
	int min = INF;
	if (depth >= vec.size())
	{
		for (int i = 0; i < N + 2; i++)
			fill(visited[i], visited[i] + M + 2, 0);
		//cout <<"d>vs "<< depth << " " << vec.size() << "\n";
		int re = simul(N, M, arr, visited, depth, vec.size(), vec, vVisited);
		min = re < min ? re : min;
		return min;
	}
	for (int i = 0; i < 4; i++)
	{
		vVisited[depth] = i;
		int re = dfs(N, M, arr, visited, depth + 1, vec.size(), vec, vVisited);
		min = re < min ? re : min;
	}

	return min;
}

int solve(int N, int M, int** arr)
{
	int** visited = new int* [(ll)N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		visited[i] = new int[(ll)M + 2];
		fill(visited[i], visited[i] + M + 2, 0);
	}
	vector<MyPoint> vec;
	vec.push_back({ 0,0 });
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] != 0 && arr[i][j] != WALL)
			{
				vec.push_back({ i,j });
			}
		}
	}
	int* vVisited = new int[(ll)vec.size() + 1];
	fill(vVisited, vVisited + (ll)vec.size() + 1, 0);
	int re = dfs(N, M, arr, visited, 1, vec.size(), vec, vVisited);
	return re;
}

int main()
{
	int N, M;
	int** arr;
	in(N, M, arr);

	int re = solve(N, M, arr);
	cout << re << "\n";

	return 0;
}

/*
5 5
6 0 6 6 0
6 4 2 0 0
2 6 0 4 6
6 6 0 6 6
0 0 0 6 6
correct = 3

*/