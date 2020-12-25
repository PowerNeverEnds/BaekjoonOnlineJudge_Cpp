#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int k, n;
		cin >> k >> n;
		int** sum = NULL;
		sum = new int* [k + 1];
		for (int i = 0; i < k+1; i++)
		{
			sum[i] = new int[n];
		}
		for (int i = 0; i < k + 1; i++)
		{
			for (int j = 0; j < n; j++)
				sum[i][j] = 0;
		}
		for (int i = 0; i < k+1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 || j == 0)
				{
					sum[i][j] = j + 1;
				}
				else
					sum[i][j] = sum[i][j - 1] + sum[i-1][j];
				
			}
		}
		cout << sum[k][n-1] << "\n";
		for (int i = 0; i < k + 1; i++)
			delete[]sum[i];
	}
}