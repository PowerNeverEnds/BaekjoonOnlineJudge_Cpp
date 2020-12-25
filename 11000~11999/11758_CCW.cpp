/**
 BOJ 11758
 - CCW
 - ¿ÀÈÄ 10:20 2020-11-27
 */

#include <iostream>

using namespace std;

int main()
{
	int x1, y1;
	cin >> x1 >> y1;
	int x2, y2;
	cin >> x2 >> y2;
	int x3, y3;
	cin >> x3 >> y3;

	x2 -= x1;
	y2 -= y1;
	x3 -= x1;
	y3 -= y1;

	x1 -= x1;
	y1 -= y1;

	int s = x2 * y3 - x3 * y2;
	if (s > 0)
		s = 1;
	else if (s < 0)
		s = -1;

	cout << s << "\n";


	return 0;
}