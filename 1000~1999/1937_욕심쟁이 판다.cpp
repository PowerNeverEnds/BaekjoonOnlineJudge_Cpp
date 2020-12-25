/*
2
https://www.acmicpc.net/board/view/35626

https://www.acmicpc.net/source/23837144

3
https://www.acmicpc.net/source/23894237
*/

#include <iostream>

typedef long long ll;

#define INF (int)1e9

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
};

//int dfs(MyPoint st, int** arr, int** visited, int depth)
//{
//	visited[st.y][st.x] = 1;
//	int max = 1;
//	bool nomove = true;
//	for (int i = 0; i < 4; i++)
//	{
//		//for (int i = 0; i < 5 + 2; i++)
//		//{
//		//	for (int j = 0; j < 5 + 2; j++)
//		//	{
//		//		cout << visited[i][j] << " ";
//		//	}cout << "\n";
//		//}cout << "\n";
//		int nY = st.y + dy[i];
//		int nX = st.x + dx[i];
//		if (arr[st.y][st.x] < arr[nY][nX])
//		{
//			nomove = false;
//			if (visited[nY][nX] == 0)
//			{
//				int re = dfs(MyPoint({ nY,nX }), arr, visited, depth + 1);
//				re = re - depth + 1;
//				max = re > max ? re : max;
//				if (visited[st.y][st.x] > max)
//					max = visited[st.y][st.x];
//				visited[st.y][st.x] = max;
//			}
//			else if (visited[st.y][st.x] < visited[nY][nX] + 1)
//				visited[st.y][st.x] = visited[nY][nX] + 1;
//			if (visited[st.y][st.x] > max)
//				max = visited[st.y][st.x];
//		}
//	}
//	//cout << st.y << " " << st.x << " " << depth<<" "<<max << "\n";
//	if (nomove == true)
//		return depth;
//	else
//		return max + depth - 1;
//}

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int dfs(MyPoint st, int** arr, int** visited)
{
	//bool noMove = true;
	if (visited[st.y][st.x] != 0)
		return visited[st.y][st.x];
	int re = 0;
	for (int i = 0; i < 4; i++)
	{
		int nY = st.y + dy[i];
		int nX = st.x + dx[i];
		if (arr[st.y][st.x] < arr[nY][nX])
		{
			//noMove = false;
			//if(visited[nY][nX]==0)
			//{
				re = myMax(re,dfs(MyPoint({ nY,nX }), arr, visited));
				//if (visited[st.y][st.x] < re + 1)
				//{
				//	visited[st.y][st.x] = re + 1;
				//}
			//}
			//else
			//{
			//	if (visited[st.y][st.x] < visited[nY][nX] + 1)
			//		visited[st.y][st.x] = visited[nY][nX] + 1;
			//}
		}
	}
	//if (noMove == true)
	//	visited[st.y][st.x] = 1;

	//return visited[st.y][st.x];
	return visited[st.y][st.x] = re + 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int** arr = new int* [(ll)n + 2];
	fill(arr, arr + n + 2, nullptr);
	for (int i = 0; i < n + 2; i++)
	{
		arr[i] = new int[(ll)n + 2];
		fill(arr[i], arr[i] + n + 2, 0);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int** visited = new int* [(ll)n + 2];
	fill(visited, visited + n + 2, nullptr);
	for (int i = 0; i < n + 2; i++)
	{
		visited[i] = new int[(ll)n + 2];
		fill(visited[i], visited[i] + n + 2, 0);
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] == 0)
			{
				//int t = dfs(MyPoint({ i,j }), arr, visited, 1);
				int t = dfs(MyPoint({ i,j }), arr, visited);
				max = t > max ? t : max;
			}
		}
	}



	cout << max << "\n";

	return 0;
}


/*
4
14 9 12 10
1 11 5 4
7 15 2 13
6 3 16 8

2
2 1
1 2

1
1

4
1 1 1 1
1 2 4 1
4 3 3 1
5 4 5 6

5
1 1 1 1 1
12 1 1 1 1
11 1 1 2 3
10 11 12 13 4
9 8 7 6 5


*/