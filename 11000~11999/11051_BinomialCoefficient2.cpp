#include <iostream>
using namespace std;

int Coefficient(int n, int k, int** mem);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int** mem = new int* [1001];
	for (int i = 0; i < 1001; i++)
	{
		mem[i] = new int[1001];
		for (int j = 0; j < 1001; j++)
		{
			mem[i][j] = -1;
		}
	}

	cout << Coefficient(n, k, mem) << "\n";

	return 0;
}

int Coefficient(int n, int k, int** mem)
{
	int result = 0;
	if (k == 0 || k == n)
	{
		result = 1;
	}
	else if (k == 1)
	{
		result = n;
	}
	else
	{
		if (mem[n][k] != -1)
		{
			result = mem[n][k];
		}
		else
		{
			result = mem[n][k] = (Coefficient(n - 1, k - 1, mem) + Coefficient(n - 1, k, mem)) % 10007;
		}
	}
	return result;
}