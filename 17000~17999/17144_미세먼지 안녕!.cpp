/**
 *    BOJ 17144
 *    - 미세먼지 안녕!
 *    author:  phcdream
 *    created: 오후 7:23 2020-12-06
**/

#include <iostream>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct MyPoint
{
	int y;
	int x;
};

void in(int& R, int& C, int& T, int***& arr)
{
	cin >> R >> C >> T;
	arr = new int** [2];
	fill(arr, arr + 2, nullptr);
	for (int k = 0; k < 2; k++)
	{
		arr[k] = new int* [(ll)R + 2];
		fill(arr[k], arr[k] + R + 2, nullptr);
		for (int i = 0; i < R + 2; i++)
		{
			arr[k][i] = new int[(ll)C + 2];
			fill(arr[k][i], arr[k][i] + C + 2, -2);
		}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> arr[0][i][j];
			if (arr[0][i][j] == -1)
				arr[1][i][j] = -1;
			else
				arr[1][i][j] = 0;
		}
	}

}

void print(int R, int C, int***& arr)
{
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i <= R; i++)
		{
			for (int j = 0; j <= C; j++)
			{
				cout << arr[k][i][j] << " ";
			}cout << "\n";
		}cout << "\n";
	}cout << "\n";
}

void spreadCell(int y, int x, int t, int***& arr)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nY = y + dy[i];
		int nX = x + dx[i];
		if (arr[(t % 2)][nY][nX] != -1 && arr[(t % 2)][nY][nX] != -2)
			cnt++;
	}

	arr[!(t % 2)][y][x] += arr[(t % 2)][y][x] - arr[(t % 2)][y][x] / 5 * cnt;
	for (int i = 0; i < 4; i++)
	{
		int nY = y + dy[i];
		int nX = x + dx[i];
		int& nCell = arr[!(t % 2)][nY][nX];
		int oCell = arr[(t % 2)][y][x];
		if (arr[(t % 2)][nY][nX] != -1 && arr[(t % 2)][nY][nX] != -2)
		{
			nCell += oCell / 5;
		}
	}
}

void spreadDust(int& R, int& C, int t, int***& arr)
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[(t % 2)][i][j] != -1 && arr[(t % 2)][i][j] != 0)
			{
				//cout << i << " " << j << "\n";
				spreadCell(i, j, t, arr);
				//print(R, C, arr);
			}
		}
	}
}

void oneStepCleaning(int R, int C, int t, int***& arr, int& y, int& x, int nD, int sizeY)
{
	int size;
	switch (nD)
	{
	case 0:
	case 2:
		size = sizeY;
		break;
	case 1:
		//size=C-1;
		//break;
	case 3:
		size = C;
		break;
	default:
		break;
	}
	for (int j = 1; j <= size - 1; j++)
	{
		int nY = y + dy[nD];
		int nX = x + dx[nD];
		//if (arr[(i % 2)][nY][nX] != -2)
		//{
		//cout << y << x <<" "<< arr[(t % 2)][y][x] <<"  " << nY << nX<< " " << arr[(t % 2)][nY][nX] << "\n";
		arr[(t % 2)][y][x] = arr[(t % 2)][nY][nX];
		y = nY;
		x = nX;
		//}
		//else
		//	break;
	}
}

void airCleaning(int R, int C, int t, int***& arr, int cleaner[])
{
	// 상단
	int y = cleaner[0];
	int x = 1;
	for (int i = 0; i < 4; i++)
	{
		int nD = (4 - i) % 4;	// 시계방향(빨아들이는 방향이므로 반대임) 0321
		//cout << nD << "\n";
		oneStepCleaning(R, C, t, arr, y, x, nD, cleaner[0]);

	}
	// 하단
	y = cleaner[1];
	x = 1;
	for (int i = 0; i < 4; i++)
	{
		int nD = (i + 2) % 4;	// 2312
		oneStepCleaning(R, C, t, arr, y, x, nD, R - cleaner[1] + 1);
	}

	// 공기청정기 원래대로,
	arr[(t % 2)][cleaner[0]][1] = -1;
	arr[(t % 2)][cleaner[1]][1] = -1;

	// 배출
	arr[(t % 2)][cleaner[0]][2] = 0;
	arr[(t % 2)][cleaner[1]][2] = 0;
}

void setZero(int R, int C, int t, int***& arr)
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[(t % 2)][i][j] != -1)
				arr[(t % 2)][i][j] = 0;
		}
	}
}

int solve(int& R, int& C, int& T, int***& arr)
{
	int cleaner[2];
	int cnt = 0;
	for (int i = 1; i <= R; i++)
		if (arr[0][i][1] == -1)
			cleaner[cnt++] = i;

	for (int i = 1 - 1; i <= T - 1; i++)
	{
		setZero(R, C, i + 1, arr);
		spreadDust(R, C, i, arr);
		//print(R, C, arr);
		airCleaning(R, C, i + 1, arr, cleaner);
	}

	//print(R, C, arr);
	int sum = 0;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			//if (arr[(T % 2)][i][j] != 0)
			//	cout <<i<<" "<<j<<" "<< arr[(T % 2)][i][j] << "\n";
			sum += arr[(T % 2)][i][j];
		}
	}

	return sum + 2;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int R, C, T;
	int*** arr;
	in(R, C, T, arr);
	//print(R, C, arr);
	int re = solve(R, C, T, arr);
	cout << re << "\n";

	return 0;
}