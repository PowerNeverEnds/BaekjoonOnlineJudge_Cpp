/*
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3

-1 -2 6
-3 -6 12
-5 -10 18
*/

#include <iostream>
using namespace std;

void matrix_input(int**& arr, int N, int M);
int matrix_multiple(int**& A, int**& B, int i, int j, int M);

int matrix_multiple(int**& A, int**& B, int i, int j, int M)
{
	int sum = 0;
	for (int k = 0; k < M; k++)
	{
		sum += A[i][k] * B[k][j];
	}
	return sum;
}

void matrix_input(int**& arr, int N, int M)
{
	arr = new int* [N];
	int e;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> e;
			arr[i][j] = e;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, K;

	int** A;
	cin >> N >> M;
	matrix_input(A, N, M);
	int** B;
	cin >> M >> K;
	matrix_input(B, M, K);

	int** C = new int*[N];
	for (int i = 0; i < N; i++)
	{
		C[i] = new int[K];
		for (int j = 0; j < K; j++)
		{
			int e;
			e = matrix_multiple(A, B, i, j, M);
			C[i][j] = e;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}