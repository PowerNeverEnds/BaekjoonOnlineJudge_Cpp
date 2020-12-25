#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int** xy = new int*[n];
	for (int i = 0; i < n; i++)
	{
		int x, y;
		xy[i] = new int[2];
		cin >> x >> y;
		xy[i][0] = x;
		xy[i][1] = y;
	}
	sort(xy, xy+n, [](int* a, int* b) {
		if (a[1] == b[1])
			return a[0] < b[0];
		else
			return a[1] < b[1];
		}
	);
	for (int i = 0; i < n; i++)
	{
		cout << xy[i][0] << " " << xy[i][1] << "\n";
	}

	return 0;
}