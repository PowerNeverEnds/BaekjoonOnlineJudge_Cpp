/**
 *    BOJ 2239
 *    - 스도쿠
 *    author:  phcdream
 *    created: 오후 10:43 2020-11-29
 */

#include <iostream>
#include <vector>

typedef long long ll;

#define N 9

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
};

void init(int**& arr)
{
	arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, -1);
	}
	for (int i = 1; i <= N; i++)
	{
		char ch;
		for (int j = 1; j <= N; j++)
		{
			cin >> ch;
			arr[i][j] = ch - '0';
		}
	}
}

bool dfs(int**& arr, vector<MyPoint>& vec, int depth, int* cols, int* rows, int* squares)
{
	// 끝까지 탐색되면 true 리턴
	if (depth >= vec.size())
	{
		return true;
	}
	for (int i = 1; i <= N; i++)
	{
		int nY = vec[depth].y;
		int nX = vec[depth].x;
		int nSQ = (nY - 1) / 3 * 3 + (nX - 1) / 3 + 1;

		// i가 이미 세로, 가로, 3X3 사각형에 있을때 continue
		if ((cols[nY] & (1 << i)) || (rows[nX] & (1 << i)) || (squares[nSQ] & (1 << i)))
		{
			continue;
		}

		cols[nY] |= 1 << i;
		rows[nX] |= 1 << i;
		squares[nSQ] |= 1 << i;
		arr[nY][nX] = i;

		bool re = dfs(arr, vec, depth + 1, cols, rows, squares);
		if (re == true)		// 끝까지 탐색되었을때
			return true;
		cols[nY] &= ~(1 << i);
		rows[nX] &= ~(1 << i);
		squares[nSQ] &= ~(1 << i);
	}

	return false;
}

int** solve(int** arr)
{
	vector<MyPoint> vec;
	int cols[(ll)N + 1] = { 0, };	// i값이 같은것
	int rows[(ll)N + 1] = { 0, };	// j값이 같은것
	int squares[(ll)N + 1] = { 0, };
	// squares 인덱스 3X3사각형
	// 123
	// 456
	// 789

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 0)
				vec.push_back(MyPoint({ i,j }));
			else
			{
				cols[i] |= 1 << arr[i][j];
				rows[j] |= 1 << arr[i][j];
				squares[(i - 1) / 3 * 3 + (j - 1) / 3 + 1] |= 1 << arr[i][j];
			}
		}
	}

	int re = dfs(arr, vec, 0, cols, rows, squares);
	//if (re == false)
	//	cout << "fails" << "\n";
	return arr;
}

void out(int n, int** re)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << re[i][j];
		}cout << "\n";
	}cout << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int** arr;
	init(arr);

	int** re = solve(arr);

	out(N, re);

	return 0;
}