#include <iostream>
using namespace std;

//template<int X, int Y, int Z>
//int stair(int n, int low, int high, int(&mem)[X][Y][Z]);
long int stair(int n, int low, int high, long int*** mem);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	//	int mem[100][10][10] = { 0, };	// [1][2][3], 1:자릿수, 2:가능한작은수, 3:가능한큰수
	long int*** mem = new long int** [101];
	for (int i = 0; i < 101; i++)
	{
		mem[i] = new long int* [10];
		for (int j = 0; j < 10; j++)
		{
			mem[i][j] = new long int[10];
		}
	}
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				mem[i][j][k] = -1;
			}
		}
	}
	cout << stair(n, 1, 9, mem) << "\n";
	return 0;
}
//template<int X, int Y, int Z>
//int stair(	int n, int low, int high, int (&mem)[X][Y][Z])
long int stair(int n, int low, int high, long int*** mem)

{
	if (n == 1)
	{
		return mem[n][low][high] = (high - low + 1);
	}
	else
	{
		if (mem[n][low][high] != -1)
		{
			return mem[n][low][high];
		}
		else
		{
			if (low == 9)
			{
				return mem[n][low][high]
					= ((stair(n - 1, low - 1 >= 0 ? low - 1 : 0, high - 1 >= 0 ? high - 1 : 0, mem) % 1000000000
					 + 0 ) % 1000000000);

			}
			if (high == 0)
			{
				return mem[n][low][high]
					= ((0
						+ stair(n - 1, low + 1 <= 9 ? low + 1 : 9, high + 1 <= 9 ? high + 1 : 9, mem) % 1000000000) % 1000000000);


			}
			return mem[n][low][high]
				= ((stair(n - 1, low - 1 >= 0 ? low - 1 : 0, high - 1 >= 0 ? high - 1 : 0, mem) % 1000000000
					+ stair(n - 1, low + 1 <= 9 ? low + 1 : 9, high + 1 <= 9 ? high + 1 : 9, mem) % 1000000000) % 1000000000);
		}
	}
}