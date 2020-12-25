/*
같은코드임, 출력문만 지운것임
*/
#include <iostream>

typedef long long ll;

using namespace std;

int signY[4] = { 1,1,-1,-1 };	// y부호 바꾸기(세로축대칭)
int signX[4] = { 1,-1,1,-1 };	// (가로축대칭)
int transY[2] = { 1,0 };	// y,x 값 바꾸기(꼭짓점대칭)
int transX[2] = { 1,0 };

int tetra[5][4][4] = {
	{
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}
};
int getSum(int f, int t, int s, int y, int x, int** arr)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int nY = int((i * signY[s] - 1.5 * signY[s]) + 1.5);
			int nX = int((j * signX[s] - 1.5 * signX[s]) + 1.5);
			if (t == 0)
				sum = sum + tetra[f][nY][nX] * arr[y + i][x + j];
			if (t == 1)
				sum = sum + tetra[f][nX][nY] * arr[y + i][x + j];
		}
	}

	return sum;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N + 4 * 2];
	fill(arr, arr + (ll)N + 4 * 2, nullptr);
	for (int i = 0; i < N + 4 * 2; i++)
	{
		arr[i] = new int[(ll)M + 4 * 2];
		fill(arr[i], arr[i] + (ll)M + 4 * 2, 0);
	}
	for (int i = 4; i < N + 4; i++)
	{
		for (int j = 4; j < M + 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	int max = 0;
	int sum = 0;
	for (int f = 0; f < 5; f++)
	{
		for (int t = 0; t < 2; t++)
		{
			for (int s = 0; s < 4; s++)
			{
				for (int i = 0; i < N + 4 * 2 - 4; i++)
				{
					for (int j = 0; j < M + 4 * 2 - 4; j++)
					{
						sum = getSum(f, t, s, i, j, arr);
						max = sum > max ? sum : max;
					}
				}
			}
		}
	}
	cout << max << "\n";

	return 0;
}


/*
#include <iostream>

typedef long long ll;

using namespace std;

int signY[4] = { 1,1,-1,-1 };	// y부호 바꾸기(세로축대칭)
int signX[4] = { 1,-1,1,-1 };	// (가로축대칭)
int transY[2] = { 1,0 };	// y,x 값 바꾸기(꼭짓점대칭)
int transX[2] = { 1,0 };

int tetra[5][4][4] = {
	{
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}
};
int getSum(int f, int t, int s, int y, int x, int** arr)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int nY = int((i * signY[s] - 1.5 * signY[s]) + 1.5);
			int nX = int((j * signX[s] - 1.5 * signX[s]) + 1.5);
			if (t == 0)
			{
				sum = sum + tetra[f][nY][nX] * arr[y + i][x + j];
				//cout << tetra[f][nY][nX] << arr[y + i][x + j] << " ";
			}
			if (t == 1)
			{
				sum = sum + tetra[f][nX][nY] * arr[y + i][x + j];
				//cout << tetra[f][nX][nY] << arr[y + i][x + j] << " ";
			}
		}
		//cout << "\n";
	}
	//cout << "\n";

	return sum;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N + 4 * 2];
	fill(arr, arr + (ll)N + 4 * 2, nullptr);
	for (int i = 0; i < N + 4 * 2; i++)
	{
		arr[i] = new int[(ll)M + 4 * 2];
		fill(arr[i], arr[i] + (ll)M + 4 * 2, 0);
	}
	for (int i = 4; i < N + 4; i++)
	{
		for (int j = 4; j < M + 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	//for (int i = 0; i < N + 4*2; i++)
	//{
	//	for (int j = 0; j < M + 4*2; j++)
	//	{
	//		cout<< arr[i][j];
	//	}
	//	cout << "\n";
	//}


	int max = 0;
	int sum = 0;
	for (int f = 0; f < 5; f++)
	{
		for (int t = 0; t < 2; t++)
		{
			for (int s = 0; s < 4; s++)
			{
				for (int i = 0; i < N + 4 * 2 - 4; i++)
				{
					for (int j = 0; j < M + 4 * 2 - 4; j++)
					{
						sum = getSum(f, t, s, i, j, arr);
						max = sum > max ? sum : max;
						//cout << i - 4 << j - 4 << sum << " " << max << "\n";
					}
				}
			}
		}
	}
	cout << max << "\n";

	//for (int s = 0; s < 4; s++)
	//{
	//	for (int i = 0; i < 4; i++)
	//	{
	//		int nY = (i * signY[s] - 1.5 * signY[s]) + 1.5;
	//		cout << nY << " ";
	//	}
	//	cout << "\n";
	//}
	return 0;
}
*/
/*
4 4
1 2 0 0
1 2 0 0
1 0 0 0
1 2 0 0

*/
