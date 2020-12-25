#include <iostream>
#include <algorithm>
using namespace std;

int myAbs(int n);
int min(int* a, int f);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int a[4] = { x,y,myAbs(w - x),myAbs(h - y) };
	int answer = min(a, 4);
	
	cout << answer << "\n";

	return 0;
}

int myAbs(int n)
{
	return n > 0 ? n : -n;
}

int min(int *a,int f)
{
	sort(&a[0],&a[f]);
	return a[0];
}