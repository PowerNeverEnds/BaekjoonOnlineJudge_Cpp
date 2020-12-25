/**
 *    BOJ 1600
 *    - 말이 되고픈 원숭이
 *    author:  phcdream
 *    created: 오전 3:42 2020-12-05
**/

#include <fstream>
#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int y;
	int x;
	int k;
	//bool operator<(const MyStruct& ms)const {	// less -> max-heap
	//	return k < ms.k;
	//}
};

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

int dhy[8] = { -2,-1,1,2,2,1,-1,-2 };
int dhx[8] = { -1,-2,-2,-1,1,2,2,1 };

void sample()
{
	ofstream cout;
	cout.open("input.txt");
	int H, W;
	H = 200;
	W = 200;
	cout << 30 << "\n";
	cout << W << " " << H << "\n";
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << 0 << " ";
		}cout << "\n";
	}cout << "\n";
	cout.close();
}

void in(int& K, int& W, int& H, int**& arr)
{
	//fstream cin;
	//cin.open("input.txt");
	cin >> K;
	cin >> W >> H;
	arr = new int* [(ll)H + 2];
	for (int i = 0; i < H + 2; i++)
	{
		arr[i] = new int[(ll)W + 2];
		fill(arr[i], arr[i] + W + 2, 1);
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> arr[i][j];
		}
	}
	//cin.close();
}

int bfs(int& K, int& W, int& H, int**& arr, int***& visited)	// 참조
{
	MyStruct st = MyStruct({ 1,1,K });
	queue<MyStruct> q;
	//priority_queue<MyStruct> q;
	visited[st.y][st.x][st.k] = 1;
	q.push(st);
	if (st.y == H && st.x == W)
		return visited[st.y][st.x][st.k];
	while (true)
	{
		//if (q.size() % 1000000 == 0)
		//	cout << q.size() << "\n";
		//for (int k = 0; k <= K; k++)
		//{
		//	for (int i = 1; i <= H; i++)
		//	{
		//		for (int j = 1; j <= W; j++)
		//		{
		//			cout << visited[i][j][k] << " ";
		//		}cout << "\n";
		//	}cout << "\n";
		//}cout << "\n";
		if (q.empty())
			break;
		st = q.front();
		//st = q.top();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];

			// 더느려짐.
			//bool noMove = false;
			//for (int k = st.k; k <= K; k++)
			//{
			//	if (visited[nY][nX][k]!=0 && visited[nY][nX][k] < visited[st.y][st.x][st.k] + 1)
			//	{
			//		noMove = true;
			//		break;
			//	}
			//}
			//if (noMove == true)
			//	continue;

			// && || visited[][][] > visited[nY][nX][] -> visiteid[st.y][st.x][] 변경
			// 해도 안해도 똑같음 다시 원래대로
			if (arr[nY][nX] == 0 && (visited[nY][nX][st.k] == 0))// || visited[nY][nX][st.k] > visited[st.y][st.x][st.k] + 1))
			{
				visited[nY][nX][st.k] = visited[st.y][st.x][st.k] + 1;
				q.push({ nY,nX,st.k });
				if (nY == H && nX == W)
				{
					return visited[nY][nX][st.k];
				}
			}
		}
		if (st.k > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int nY = st.y + dhy[i];
				int nX = st.x + dhx[i];
				if (1 <= nY && nY <= H && 1 <= nX && nX <= W)
				{
					//bool noMove = false;
					//for (int k = st.k; k <= K; k++)
					//{
					//	if (visited[nY][nX][k] != 0 && visited[nY][nX][k] < visited[st.y][st.x][st.k] + 1)
					//	{
					//		noMove = true;
					//		break;
					//	}
					//}
					//if (noMove == true)
					//	continue;

					// && || visited[][][] > visited[nY][nX][] -> visiteid[st.y][st.x][] 변경
					// 해도 안해도 똑같음
					if (arr[nY][nX] == 0 && (visited[nY][nX][st.k - 1] == 0))// || visited[nY][nX][st.k - 1] > visited[st.y][st.x][st.k] + 1))
					{
						visited[nY][nX][st.k - 1] = visited[st.y][st.x][st.k] + 1;
						q.push({ nY,nX,st.k - 1 });
						if (nY == H && nX == W)
						{
							return visited[nY][nX][st.k - 1];	// st.k-1
						}
					}
				}
			}
		}
	}

	return -1;
}

int solve(int& K, int& W, int& H, int**& arr)
{
	int*** visited = new int** [(ll)H + 2];
	fill(visited, visited + H + 2, nullptr);
	for (int i = 0; i < H + 2; i++)
	{
		visited[i] = new int* [(ll)W + 2];
		fill(visited[i], visited[i] + W + 2, nullptr);
		for (int j = 0; j < W + 2; j++)
		{
			visited[i][j] = new int[(ll)K + 1];
			fill(visited[i][j], visited[i][j] + K + 1, 0);
		}
	}

	int re = bfs(K, W, H, arr, visited);
	//for (int k = 0; k <= K; k++)
	//{
	//	for (int i = 1; i <= H; i++)
	//	{
	//		for (int j = 1; j <= W; j++)
	//		{
	//			cout << visited[i][j][k] << " ";
	//		}cout << "\n";
	//	}cout << "\n";
	//}cout << "\n";
	if (re == -1)
		return -1;
	else
		return re - 1;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//sample();

	int K;
	int W, H;
	int** arr;
	in(K, W, H, arr);

	int re = solve(K, W, H, arr);
	cout << re << "\n";

	return 0;
}
/*
30
20 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

30
3 3
0 0 0
0 0 0
0 0 0

30
10 10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

1
10 10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

2
10 10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

8
20 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0


*/