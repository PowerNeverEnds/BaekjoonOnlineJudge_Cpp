/*
https://www.acmicpc.net/board/view/47687
*/

/*
#include <iostream>
#include <cstring>

using namespace std;

int map[100][100];
int dp[100][100];

int N;

int dfs(int y, int x) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == -1)
				cout << 0;
			else
				cout << dp[i][j];
		}cout << "\n";
	}cout << "\n";
	// 끝에 도달한 경우라면
	if (y == N - 1 && x == N - 1) {
		return 1;
	}

	// 아직 방문하지 않은 곳이라면
	if (dp[y][x] == -1) {
		dp[y][x] = 0;

		int nextRight = x + map[y][x];		// 오른쪽으로 가는 경우 
		int nextBottom = y + map[y][x];		// 아래로 가는 경우

		// 지도 범위 내라면
		if (nextRight < N) {
			dp[y][x] += dfs(y, nextRight);
		}

		if (nextBottom < N) {
			dp[y][x] += dfs(nextBottom, x);
		}
	}

	return dp[y][x];
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0) << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == -1)
				cout << 0;
			else
				cout << dp[i][j];
		}cout << "\n";
	}cout << "\n";

	return 0;
}
*/


/*
5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1


*/



#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int* [N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		fill(arr[i], arr[i] + N, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	ll** visited = new ll* [N];
	fill(visited, visited + N, nullptr);
	for (ll i = 0; i < N; i++)
	{
		visited[i] = new ll[N];
		fill(visited[i], visited[i] + N, 0);
	}

	visited[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] != 0 && arr[i][j] != 0)
			{
				if (i + arr[i][j] < N)
				{
					visited[i + arr[i][j]][j] += visited[i][j];
				}
				if (j + arr[i][j] < N)
				{
					visited[i][j + arr[i][j]] += visited[i][j];
				}
			}
		}
	}

	cout << visited[N - 1][N - 1] << "\n";

	return 0;
}



/*
4
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0


3
1 1 1
1 1 1
1 1 0

7
2 3 3 1 0 0 0
1 2 1 3 0 0 0
1 2 3 1 0 0 0
3 1 1 1 2 0 2
0 0 0 1 0 0 0
0 0 0 2 1 1 1
0 0 0 0 2 0 0

3 4 12
*/




/*
#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int* [N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		fill(arr[i], arr[i] + N, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	ll** visited = new ll* [N];
	fill(visited, visited + N, nullptr);
	for (ll i = 0; i < N; i++)
	{
		visited[i] = new ll[N];
		fill(visited[i], visited[i] + N, 0);
	}


	visited[0][0] = 1;
	//for (int i = 0; i < N && arr[0][i] != 0; i += arr[0][i])
	//	visited[0][i] = 1;
	//for (int i = 0; i < N && arr[i][0] != 0; i += arr[i][0])
	//	visited[i][0] = 1;
	//visited[0][0] = 0;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << visited[i][j];
	//	}cout << "\n";
	//}cout << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		//for (int j = i; j < N; j++)
		{
			if (visited[i][j] != 0 && arr[i][j] != 0)
			{
				if (i + arr[i][j] < N)
				{
					visited[i + arr[i][j]][j] += visited[i][j];
				}
				if (j + arr[i][j] < N)
				{
					visited[i][j + arr[i][j]] += visited[i][j];
				}
			}


			//if (visited[i][j] != 0 && arr[i][j] != 0)
			//{
			//	if (i + arr[i][j] < N)
			//	{
			//		visited[i + arr[i][j]][j] += visited[i][j];
			//	}
			//}
			//if (visited[j][i] != 0 && arr[j][i] != 0)
			//{
			//	if (i + arr[j][i] < N)
			//	{
			//		visited[j][i + arr[j][i]] += visited[j][i];
			//	}
			//}
		}
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cout << visited[i][j];
		//	}cout << "\n";
		//}cout << "\n";

	}
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << visited[i][j];
	//	}cout << "\n";
	//}cout << "\n";

	cout << visited[N - 1][N - 1] << "\n";

	return 0;
}




*/