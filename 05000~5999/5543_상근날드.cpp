#include <iostream>
using namespace std;

void selMenu(int& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		a = e < a ? e : a;
	}
}
int main()
{
	int a = 2000;
	int b = 2000;
	
	selMenu(a, 3);
	selMenu(b, 2);
	
	cout << a + b - 50 << "\n";

	return 0;
}