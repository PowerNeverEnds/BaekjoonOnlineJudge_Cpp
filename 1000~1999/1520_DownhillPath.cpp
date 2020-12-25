#include <iostream>
using namespace std;

int f(int n);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	int** arr = new int* [m];
	int** count = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
		count[i] = new int[n];
		//for (int j = 0; j < n; j++)
		//{
		//	cin >> arr[i][j];
		//}
	}

	count[0][0] = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

		}
	}
	f(10000);
	return 0;
}

int f(int n)
{
	cout << n << "\n";
	if (n == 0)
		return 1;
	else return f(n - 1);
}