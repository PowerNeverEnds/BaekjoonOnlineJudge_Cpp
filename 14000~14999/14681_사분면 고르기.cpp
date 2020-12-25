#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	if (0 < x && 0 < y)
		cout << 1 << "\n";
	if (0 > x && 0 < y)
		cout << 2 << "\n";
	if (0 > x && 0 > y)
		cout << 3 << "\n";
	if (0 < x && 0 > y)
		cout << 4 << "\n";

	return 0;
}