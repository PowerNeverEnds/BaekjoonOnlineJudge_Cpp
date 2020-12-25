/**
 BOJ 3003
 - 킹, 퀸, 룩, 비숍, 나이트, 폰
 - 오후 9:17 2020-11-27
 */

#include <iostream>

using namespace std;

int main()
{
	int k, q, r, b, kn, p;
	cin >> k >> q >> r >> b >> kn >> p;
	cout << 1 - k << " " << 1 - q << " " << 2 - r << " " << 2 - b << " " << 2 - kn << " " << 8 - p << "\n";
	
	return 0;
}