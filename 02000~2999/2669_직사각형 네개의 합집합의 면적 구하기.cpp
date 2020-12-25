#include <iostream>
using namespace std;

bool arr[101][101];

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		for (int iy = y1; iy < y2; iy++)
		{
			for (int ix = x1; ix < x2; ix++)
			{
				arr[iy][ix] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (arr[i][j])
				cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}