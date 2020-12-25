#include <iostream>
using namespace std;

int isItSame(int a, int b, int c, int d);
int colorPaper(bool** arr, int x, int y, int m, int& wCount, int& bCount);
//template<int X, int Y>
//void foo(int (&a)[X][Y]);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	bool** arr = new bool* [n + 1];

	for (int i = 0; i < n + 1; i++)
	{
		arr[i] = new bool[n + 1];
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)	// 계산하기 편하라고 1부터 입력받음.
				arr[i][j] = 0;
			else
				cin >> arr[i][j];
		}
	}
	//for (int i = 0; i < n + 1; i++)
	//{
	//	for (int j = 0; j < n + 1; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	int wCount = 0, bCount = 0;
	int answer=colorPaper(arr, n, n, n/2, wCount, bCount);
	if (answer == 0)
		wCount++;
	else if (answer == 1)
		bCount++;
	cout << wCount << "\n";
	cout << bCount << "\n";

	//int abc[20][20] = { 0, };
	//foo(abc);
	return 0;
}

//template<int X, int Y>
//void foo(int (&a)[X][Y])
//{
//	for (int i = 0; i < X; i++)
//	{
//		for (int j = 0; j < Y; j++)
//		{
//			cout << ".";
//		}
//		cout << "\n";
//	}
//}
int colorPaper(bool** arr, int x, int y, int m, int& wCount, int& bCount)
{
	//cout << x << " " << y << " " << m << " " << arr[y][x] << "\n";
	if (m == 0)
	{
		return arr[x][y];
	}
	int udlr[4];	// 0 upLeft, 1 upRight, 2 downLeft, 3 downRight
	udlr[0] = colorPaper(arr, x - m, y - m, m / 2, wCount, bCount);
	udlr[1] = colorPaper(arr, x, y - m, m / 2, wCount, bCount);
	udlr[2] = colorPaper(arr, x - m, y, m / 2, wCount, bCount);
	udlr[3] = colorPaper(arr, x, y, m/2, wCount, bCount);	// m-m 실수한거 m/2 변경
	int same = isItSame(udlr[0], udlr[1], udlr[2], udlr[3]);
	if (same == 0)
	{
		return 0;
	}
	else if (same == 1)
	{
		return 1;
	}
	else if (same == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			//cout << x << " " << y << " " << m<<" "<<i<< " " << udlr[i] << "\n";
			if (udlr[i] == 0)
				wCount++;
			else if (udlr[i] == 1)
				bCount++;
		}
		return 2;
	}
}

int isItSame(int a, int b, int c, int d)
{
	if (a != 2 || b != 2 || c != 2 || d != 2)
	{
		if (a == b && b == c && c == d)
		{
			return a;
		}
		else
			return 2;
	}
	else
		return 2;
}


/*
4
1 1 0 0
1 1 0 0
0 0 0 1
0 0 1 1


*/