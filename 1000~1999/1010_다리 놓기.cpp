#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;

		int** arr = new int* [N];
		fill(arr, arr + N, nullptr);
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[M];
			fill(arr[i], arr[i] + M, 0);
		}
		for (int i = 0; i < M; i++)
			arr[0][i] = 1;
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				int s = 0;
				for (int k = 0; k < j; k++)
				{
					s += arr[i - 1][k];
				}
				arr[i][j] = s;
			}
		}
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < M; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}cout << "\n";
		//}
		int s = 0;
		for (int i = 0; i < M; i++)
			s += arr[N - 1][i];
		cout << s << "\n";
	}

	return 0;
}