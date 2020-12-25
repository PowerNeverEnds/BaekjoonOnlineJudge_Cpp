#include <iostream>
using namespace std;

int n;

int paper[3000][3000];
int mem[3][2] = { {-1},{0},{1} };

int px[] = {0,1,2,0,1,2,0,1,2};
int py[] = {0,0,0,1,1,1,2,2,2};

int pd(int y, int x, int size)
{
	bool b[3];
	for (int i = 0; i < 3; i++)
		b[i] = true;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (paper[i][j] != mem[k][0])
					b[k] = false;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (b[i] == true)
		{
			//cout << y << " " << x << " " << size <<" "<<mem[i][0]<<" "<<mem[i][1]<< "\n";
			mem[i][1]++;
			return 0;
		}
	}
	if (size == 1)
		return 0;
	for (int i = 0; i < 9; i++)
	{
		pd(y+py[i]*size/3,x+px[i]*size/3,size/3);
	}
	return 0;

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}
	pd(0, 0, n);
	for (int i = 0; i < 3; i++)
	{
		//cout << mem[i][0] << " ";
		cout << mem[i][1] << "\n";
	}
	return 0;
}