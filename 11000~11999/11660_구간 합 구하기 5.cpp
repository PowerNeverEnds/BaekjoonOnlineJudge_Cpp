#include <iostream>

typedef long long ll;

using namespace std;

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** arr = new int* [(ll)N+1];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N+1; i++)
	{
		arr[i] = new int[(ll)N+1];
		fill(arr[i], arr[i] + N+1, 0);
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int** sumArr = new int* [(ll)N+1];
	fill(sumArr, sumArr + N+1, nullptr);
	for (int i = 0; i < N+1; i++)
	{
		sumArr[i] = new int[(ll)N+1];
		fill(sumArr[i], sumArr[i] + N+1, 0);
	}

	sumArr[1][1] = arr[1][1];
	for (int i = 2; i <= N; i++)
	{
		sumArr[i][1] = sumArr[i - 1][1] + arr[i][1];
		sumArr[1][i] = sumArr[1][i - 1] + arr[1][i];
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			sumArr[i][j] = arr[i][j]+sumArr[i-1][j]+sumArr[i][j-1]-sumArr[i - 1][j - 1];
		}
	}

	int* out = new int[M];
	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		swap(x1, y1);
		swap(x2, y2);
		int plus = sumArr[y2][x2]+sumArr[y1-1][x1-1];
		int minus = sumArr[y2][x1-1]+sumArr[y1-1][x2];
		out[i] = plus - minus;
	}

	for (int i = 0; i < M; i++)
	{
		cout << out[i] << "\n";
	}

	return 0;
}