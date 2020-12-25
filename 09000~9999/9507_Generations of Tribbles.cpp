/**
 *    BOJ 9507
 *    - Generations of Tribbles
 *    author:  phcdream
 *    created: ¿ÀÀü 12:41 2020-11-30
 */

#include <iostream>

typedef long long ll;

#define N 67

using namespace std;

ll koong(int n, ll* mem)
{
	if (n < 2)
		return mem[n] = 1;
	else if (n == 2)
		return mem[n] = 2;
	else if (n == 3)
		return mem[n] = 4;
	else if (mem[n] != 0)
		return mem[n];
	else
	{
		//cout << n << "\n";
		return mem[n] = koong(n - 1, mem) + koong(n - 2, mem) + koong(n - 3, mem) + koong(n - 4, mem);
	}
}

void init(ll* mem)
{
	koong(N, mem);
}

ll solve(int n, ll* mem)
{
	return mem[n];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll mem[N + 1] = { 0, };
	init(mem);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		ll re = solve(n, mem);
		cout << re << "\n";
	}

	return 0;
}