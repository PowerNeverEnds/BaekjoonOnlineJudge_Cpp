#include <iostream>

using namespace std;

void printStar(int i, int n)
{

	for (int j = 0; j < i; j++)
	{
		cout << "*";
	}
}
void printBlank(int i, int n)
{

	for (int j = n; j > i; j--)
	{
		cout << " ";
	}
}
int main()
{
	int n;
	cin >> n;

	int d = 1;
	for (int i = 1; i >= 1; i += d)
	{
		printStar(i, n);
		printBlank(i, n);
		printBlank(i, n);
		printStar(i, n);
		cout << "\n";
		if (i == n)
			d = -1;
	}
	return 0;
}