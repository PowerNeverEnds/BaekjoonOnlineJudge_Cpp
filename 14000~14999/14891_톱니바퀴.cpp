#include <iostream>

using namespace std;

int main()
{
	int arr[4][8];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char ch;
			cin >> ch;
			arr[i][j] = ch - '0';
		}
	}
	int K;
	cin >> K;
	int p[4] = { 0, };
	for (int i = 0; i < K; i++)
	{
		int n, d;
		cin >> n >> d;
		int td = d;
		p[n - 1] = (p[n - 1] + -d + 8) % 8;
		for (int j = n - 1; j < 4 - 1; j++)
		{
			if (arr[j][(p[j] + 2 + td + 8) % 8] != arr[j + 1][(p[j + 1] - 2 + 8) % 8])
			{
				td = -td;
				p[j + 1] = (p[j + 1] + -td + 8) % 8;
			}
			else
				break;
		}
		td = d;
		for (int j = n - 1; j > 0; j--)
		{
			if (arr[j][(p[j] - 2 + 8 + td) % 8] != arr[j - 1][(p[j - 1] + 2 + 8) % 8])
			{
				td = -td;
				p[j - 1] = (p[j - 1] + -td + 8) % 8;
			}
			else
				break;
		}
		//for (int j = 0; j < 4; j++)
		//{
		//	cout << p[j] << "\n";
		//	for (int i = 0; i < 8; i++)
		//	{
		//		cout << arr[j][i];
		//	}cout << "\n";
		//}cout << "\n";
	}

	int sum = 0;
	int com = 1;
	for (int i = 0; i < 4; i++)
	{
		sum += arr[i][p[i]] * com;
		com *= 2;
	}

	cout << sum << "\n";

	return 0;
}

/*
00100001
11111101
10000000
00000000
1
3 1

3
*/