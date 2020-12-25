/**
 *    BOJ 4485
 *    - 녹색 옷 입은 애가 젤다지?
 *    author:  phcdream
 *    created: 오전 7:52 2020-12-05
**/


#include <iostream>
#include <queue>

typedef long long ll;

#define INF ((int)1e4+7)

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
	int w;
	bool operator<(const MyPoint& mp) const {	// less -> max-heap
		return w > mp.w;
	}
};

void bfs(int N, int** arr, int** visited)
{
	priority_queue<MyPoint> pq;
	MyPoint st = MyPoint({ 1,1,arr[1][1] });
	visited[st.y][st.x] = st.w;
	pq.push(st);
	while (true)
	{
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		cout << visited[i][j] << " ";
		//	}cout << "\n";
		//}cout << "\n";;

		if (pq.empty())
			break;
		st = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = st.y + dy[i];
			int nX = st.x + dx[i];
			if (arr[nY][nX] != -1)
			{
				if (st.w + arr[nY][nX] < visited[nY][nX])
				{
					visited[nY][nX] = st.w + arr[nY][nX];
					pq.push({ nY,nX,visited[nY][nX] });
				}
			}
		}
	}
}

int main()
{
	for (int t = 1;; t++)
	{
		int N;
		cin >> N;
		if (N == 0)
			break;
		int** arr = new int* [(ll)N + 2];
		fill(arr, arr + N + 2, nullptr);
		for (int i = 0; i < N + 2; i++)
		{
			arr[i] = new int[(ll)N + 2];
			fill(arr[i], arr[i] + N + 2, -1);
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> arr[i][j];

		int** visited = new int* [(ll)N + 2];
		fill(visited, visited + N + 2, nullptr);
		for (int i = 0; i < N + 2; i++)
		{
			visited[i] = new int[(ll)N + 2];
			fill(visited[i], visited[i] + N + 2, INF);
		}
		bfs(N, arr, visited);
		cout << "Problem " << t << ": " << visited[N][N] << "\n";
	}

	return 0;
}

/*
내려갔다가 위로도 갈수있음 dp가아님 bfs 로 풀어여함.
*/
//#include <iostream>
//
//typedef long long ll;
//
//using namespace std;
//
//int myMin(int a, int b)
//{
//	return a <= b ? a : b;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//
//	for (int t = 1;; t++)
//	{
//		int N;
//		cin >> N;
//		if (N == 0)
//			break;
//		int* dp = new int[(ll)N + 1];
//		fill(dp, dp + N + 1, 0);
//		for (int i = 0; i < N; i++)
//		{
//			int* arr = new int[(ll)N + 1];
//			fill(arr, arr + N + 1, 0);
//			if (i == 0)
//			{
//				for (int j = 0; j < N; j++)
//				{
//					cin >> arr[j];
//					if (j == 0)
//						dp[j] = arr[j];
//					else
//						dp[j] = dp[j - 1] + arr[j];
//				}
//				continue;
//			}
//			for (int j = 0; j < N; j++)
//			{
//				int prev = arr[j];
//				cin >> arr[j];
//				if (j == 0)
//				{
//					dp[j] += arr[j];
//				}
//				else
//				{
//					dp[j] = arr[j] + myMin(dp[j-1], dp[j]);
//
//				}
//			}
//			for (int j = 0; j < N; j++)
//				cout << dp[j] << " ";
//			cout << "\n";
//		}
//		cout << "Problem " << t << ": " << dp[N - 1] << "\n";
//	}
//
//	return 0;
//}