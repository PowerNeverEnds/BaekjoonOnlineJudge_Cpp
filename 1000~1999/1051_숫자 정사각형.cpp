/**
 *    BOJ 1051
 *    - 숫자 정사각형
 *    author:  phcdream
 *    created: 오전 8:53 2020-12-05
**/

#include <iostream>

typedef long long ll;

using namespace std;

bool isSame(int a, int b, int c, int d)
{
	if (a == b && b == c && c == d)
		return true;
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	char** arr = new char* [(ll)N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[(ll)M];
		fill(arr[i], arr[i] + M, NULL);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int max = 0;
	for (int k = 0; k < N + M; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i + k >= N)
				break;
			for (int j = 0; j < M; j++)
			{
				if (j + k >= M)
					break;
				bool bis = isSame(arr[i][j], arr[i + k][j], arr[i + k][j + k], arr[i][j + k]);
				if (bis == true)
				{
					max = k;
				}
			}
		}
	}
	cout << (max + 1) * (max + 1) << "\n";

	return 0;
}