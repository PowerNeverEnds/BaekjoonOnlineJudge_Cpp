#include <iostream>
using namespace std;

int T;
int dp[2000001][3];
int result;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int f, g;
	f = 3; g = 2;
	for (int i = 1; i < n; i++)
	{
		f = (f + 2 * g);
		g = (f - g);
		f %= 9901;
		g %= 9901;
	}
	cout << f << "\n";

	return 0;
}
/*
1
0 1 2
3
f(1)=3, g(1)=2
f(x)=f(x-1)+2(g(x-1))
g(x)=f(x)-g(x-1)
2
00 01 02
10 12
20 21
7=3+2(2)
f(1)+2g(1)

3
000 001 002
010 012
020 021
100 101 102
120 121
200 201 202
210 212
7+5*2
f(2)+2(g2)

4
f(3)+2g(3)



f(x)=f(x-1)+2(g(x-1))
g(x)=f(x)-g(x-1)
g(x-1)=f(x)-g(x)
f(x)=g(x)+g(x-1)


*/