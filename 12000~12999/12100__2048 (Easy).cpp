/**
 *    BOJ 12100
 *    - 2048 (Easy)
 *    author:  phcdream
 *    created: 오후 10:41 2020-12-12
**/

#include <iostream>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

void in(int& N, int**& arr)
{
	cin >> N;
	arr = new int* [(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, 0);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void print(int N, int**& arr)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
}

void mySum(int N, int**& arr, int d)
{
	//int si, sj;
	//int ei, ej;
	//int ci, cj;
	//int dY, dX;
	//switch (d)
	//{
	//case 0:		// 위쪽
	//	si = 1;
	//	sj = 1;
	//	ei = N;
	//	ej = N;
	//	ci = 1;
	//	cj = 1;
	//	dY = 3;
	//	dX = 4;
	//case 1:
	//case 2:
	//case 3:
	//default:
	//	break;
	//}
	//for (int i = si; i <= ei; i+=ci)
	//{
	//	int prev = 0;
	//	int pi, pj;
	//	for (int j = sj; j <= ej; j+=cj)
	//	{
	//		int nY = dy[dY] * i + dx[dY] * j;
	//		int nX = dy[dX] * i + dx[dX] * j;
	//		if (prev == arr[nY][nX])
	//		{
	//			arr[pj][pi] *= 2;
	//			arr[nY][nX] = 0;
	//			prev = 0;
	//		}
	//		else if (prev != arr[j][i])
	//		{
	//			prev = arr[j][i];
	//			pi = i;
	//			pj = j;
	//		}
	//	}
	//}
	switch (d)
	{
	case 0:
	{
		// 상(위쪽)
		for (int i = 1; i <= N; i++)
		{
			int prev = -1;
			int pi = i, pj = 1;
			for (int j = 1; j <= N; j++)
			{
				if (arr[j][i] == 0)		// 추가.d
					continue;
				if (prev == arr[j][i])
				{
					arr[pj][pi] *= 2;
					arr[j][i] = 0;
					prev = -1;
				}
				else if (prev != arr[j][i])
				{
					prev = arr[j][i];
					pi = i;
					pj = j;
				}
			}
		}
	}
	break;
	case 1:
	{
		// 좌(왼쪽)
		for (int i = 1; i <= N; i++)
		{
			int prev = -1;
			int pi = i, pj = 1;
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] == 0)		// 추가.d
					continue;
				if (prev == arr[i][j])
				{
					arr[pi][pj] *= 2;
					arr[i][j] = 0;
					prev = -1;
				}
				else if (prev != arr[i][j])
				{
					prev = arr[i][j];
					pi = i;
					pj = j;
				}
			}
		}
	}
	break;
	case 2:
	{
		// 하(아래)
		for (int i = 1; i <= N; i++)
		{
			int prev = -1;
			int pi = i, pj = N;
			for (int j = N; j >= 1; j--)
			{
				if (arr[j][i] == 0)		// 추가.d
					continue;
				if (prev == arr[j][i])
				{
					arr[pj][pi] *= 2;
					arr[j][i] = 0;
					prev = -1;
				}
				else if (prev != arr[j][i])
				{
					prev = arr[j][i];
					pi = i;
					pj = j;
				}
			}
		}
	}
	break;
	case 3:
	{
		// 우(오른쪽)
		for (int i = 1; i <= N; i++)
		{
			int prev = -1;
			int pi = i, pj = N;
			for (int j = N; j >= 1; j--)
			{
				if (arr[i][j] == 0)		// 추가.d
					continue;
				if (prev == arr[i][j])
				{
					arr[pi][pj] *= 2;
					arr[i][j] = 0;
					prev = -1;
				}
				else if (prev != arr[i][j])
				{
					prev = arr[i][j];
					pi = i;
					pj = j;
				}
			}
		}
	}
	break;
	default:
		break;
	}

}

void myMove(int N, int**& arr, int d)
{
	switch (d)
	{
	case 0:
	{
		// 상(위쪽)
		for (int i = 1; i <= N; i++)
		{
			int p = 0;
			int pi = i, pj = 1;
			for (int j = 1; j <= N; j++)
			{
				if (arr[j][i] != 0)
				{
					if (pj != j)
					{
						arr[pj][pi] = arr[j][i];
						arr[j][i] = 0;
					}
					pj++;
				}
			}
		}
	}
	break;
	case 1:
	{
		// 좌(왼쪽)
		for (int i = 1; i <= N; i++)
		{
			int prev = 0;
			int pi = i, pj = 1;
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] != 0)
				{
					if (pj != j)
					{
						arr[pi][pj] = arr[i][j];
						arr[i][j] = 0;
					}
					pj++;
				}
			}
		}
	}
	break;
	case 2:
	{
		// 하(아래)
		for (int i = 1; i <= N; i++)
		{
			int prev = 0;
			int pi = i, pj = N;
			for (int j = N; j >= 1; j--)
			{
				if (arr[j][i] != 0)
				{
					if (pj != j)
					{
						arr[pj][pi] = arr[j][i];
						arr[j][i] = 0;
					}
					pj--;

				}
			}
		}
		break;
	case 3:
	{
		// 우(오른쪽)
		for (int i = 1; i <= N; i++)
		{
			int prev = 0;
			int pi = i, pj = N;
			for (int j = N; j >= 1; j--)
			{
				if (arr[i][j] != 0)
				{
					if (pj != j)
					{
						arr[pi][pj] = arr[i][j];
						arr[i][j] = 0;
					}
					pj--;
				}
			}
		}
	}
	break;
	default:
		break;
	}

	}
}

int dfs(int N, int**& arr, int depth, int dMax, int prev)
{
	int max = 0;
	if (depth > dMax)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				max = arr[i][j] > max ? arr[i][j] : max;
			}
		}
		return max;
	}
	for (int i = 0; i < 4; i++)
	{
		//if (i == prev)		// 반례있음.
		//	continue;
		int** nArr = new int* [(ll)N + 2];
		fill(nArr, nArr + N + 2, nullptr);
		for (int i = 0; i < N + 2; i++)
		{
			nArr[i] = new int[(ll)N + 2];
			fill(nArr[i], nArr[i] + N + 2, 0);
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				nArr[i][j] = arr[i][j];
			}
		}

		//cout << "d "<<i<<" "<<"depth "<<depth << "\n";
		//if(i==0 || i==1)
		//print(N, nArr);

		mySum(N, nArr, i);
		//if (i == 0 || i == 1)
		//print(N, nArr);
		myMove(N, nArr, i);

		//if (i == 0 || i == 1)
		//print(N, nArr);
//		cout << "\n";

		int re = dfs(N, nArr, depth + 1, dMax, i);
		max = re > max ? re : max;

		delete[] nArr;
	}
	return max;
}

int solve(int N, int**& arr)
{
	int re = dfs(N, arr, 1, 5, 0);
	return re;
}
int main()
{
	int N;
	int** arr;
	in(N, arr);

	int re = solve(N, arr);
	cout << re << "\n";

	return 0;
}

/*

3
2 2 2
4 4 4
8 8 8


4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

3
1 1 1
1 1 1
1 1 1

2
1 1
1 1


20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

4
2 4 16 8
8 4 0 0
16 8 2 0
2 8 2 0

4
2 4 8 2
2 4 0 0
2 0 0 0
2 0 2 0	

1
4

2
1 0
0 1

2
1 2
2 1

2
1 2
0 1

1
1

2
0 4
0 0

4
0 0 0 0
16 1 1 0
8 4 2 0
0 0 0 0

https://www.acmicpc.net/board/view/50764

https://www.acmicpc.net/board/view/24061
5

2 2 4 8 16

0 0 0 0 0

0 0 0 0 0

0 0 0 0 0

2 2 4 8 16
*/