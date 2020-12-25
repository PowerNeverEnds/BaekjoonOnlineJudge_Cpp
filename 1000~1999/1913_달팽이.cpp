/**
 *    BOJ 1913
 *    - 달팽이
 *    author:  phcdream
 *    created: 오전 2:27 2020-12-07
**/

#include <iostream>

typedef long long ll;

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

int main()
{
	int N;
	cin >> N;
	int NN;
	cin >> NN;
	int** arr = new int*[(ll)N + 2];
	fill(arr, arr + N + 2, nullptr);
	for (int i = 0; i < N + 2; i++)
	{
		arr[i] = new int[(ll)N + 2];
		fill(arr[i], arr[i] + N + 2, 0);
	}

	int y = 1;
	int x = 1;
	int d = 2;
	int num = N * N;
	int yy=1;
	int xx=1;
	arr[y][x] = num--;
	while (true)
	{
		if (num <= 0)
			break;
		while (true)
		{
			int nY = y + dy[d];
			int nX = x + dx[d];
			//cout << nY << " " << nX << "\n";
			if (1<=nY && nY<=N && 1<=nX && nX<=N && arr[nY][nX] == 0)
			{
				if (num == NN)
				{
					yy = nY;
					xx = nX;
				}
				arr[nY][nX] = num--;
				y = nY;
				x = nX;
			}
			else
			{
				d = (d + 1) % 4;
				break;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[i][j] << " ";
		}cout << "\n";
	}

	cout << yy << " " << xx << "\n";

	return 0;
}