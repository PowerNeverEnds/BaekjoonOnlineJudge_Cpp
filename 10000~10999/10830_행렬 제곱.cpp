#include <iostream>
#define DIV 1000

typedef unsigned long long ull;

using namespace std;

int** matrix_power(int**& A, ull B, int N);
int** matrix_multiple(int**& A, int**& B, int N);

int** matrix_multiple(int**& A, int**& B, int N)
{
	int** C = new int* [N];
	for (int i = 0; i < N; i++)
	{
		C[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				C[i][j] += (A[i][k] * B[k][j]) % DIV;
			}
			C[i][j] %= DIV;
		}
	}
	return C;
}

int** matrix_power(int**& A, ull B, int N)
{
	if (B == 1)
	{
		return A;
	}
	if (B % 2 == 0)
	{
		int** T = new int* [N];
		for (int i = 0; i < N; i++)
			T[i] = new int[N];
		T = matrix_power(A, B / 2, N);
		return matrix_multiple(T, T, N);
	}
	else
	{
		int** T = new int* [N];
		for (int i = 0; i < N; i++)
			T[i] = new int[N];
		T = matrix_power(A, B - 1, N);
		return matrix_multiple(A, T, N);
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	ull B;
	cin >> N >> B;

	int** A = new int* [N];
	int e;
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> e;
			A[i][j] = e;
		}
	}

	int** S = new int* [N];
	S = matrix_power(A, B, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << (S[i][j]%=DIV) << " ";
		}
		cout << "\n";
	}

	return 0;
}