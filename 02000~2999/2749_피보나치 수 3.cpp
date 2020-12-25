#include <iostream>
#define DIV 1000000
typedef unsigned long long ull;

using namespace std;

void matrix_multiple(ull a[2][2], ull b[2][2])
{
	ull t[2][2] = { 0, };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				t[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = t[i][j]%DIV;

}

int main()
{
	ull n;
	cin >> n;
		if (n < 2)
		{
			cout << n << "\n";
		}
		else
		{
			n -= 1;
			ull A[2][2] = {
				{ 0, 1},
				{ 1, 1} };
			ull B[2][2] = {
				{ 0, 1},
				{ 1, 1} };
			while (n > 0)
			{
				if (n % 2 == 1)
				{
					matrix_multiple(B, A);
				}
				matrix_multiple(A, A);
				n /= 2;
			}
			cout << B[0][1] << "\n";
		}
	return 0;
}