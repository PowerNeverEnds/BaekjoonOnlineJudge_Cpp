/**
 *    BOJ 2342
 *    - Dance Dance Revolution
 *    author:  phcdream
 *    created: 오후 6:20 2020-11-30
 */

#include <iostream>
#include <vector>

typedef long long ll;

#define INF (int(4e5 +7))

using namespace std;

void in(int& N,vector<int>& vec, int***& dp)
{
	while (true)
	{
		int e;
		cin >> e;
		vec.push_back(e);
		if (e == 0)
			break;
	}
	N = vec.size();
	dp = new int** [(ll)N + 1];
	fill(dp, dp + N + 1 , nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = new int*[5];
		fill(dp[i], dp[i] + 5, nullptr);
		for (int j = 0; j < 5; j++)
		{
			dp[i][j] = new int[5];
			fill(dp[i][j], dp[i][j] + 5, INF);
		}
	}
}

int moveF(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 2;
	}
	else if (a  == b)
	{
		return 1;
	}
	else if (a % 2 == b % 2)
	{
		return 4;
	}
	else
	{
		return 3;
	}
}

void setDp(int& current, int f, int& prev)
{
	if (prev + f < current)
		current = prev + f;
}

int solve(int N, vector<int> vec, int*** dp)
{
	int st = vec[0];
	if (st == 0)
		return 0;
	dp[0][st][0] = 2;
	dp[0][0][st] = 2;
	for (int i = 1; i < vec.size()-1; i++)
	{
		st = vec[i];
		for (int j = 0; j <= 4; j++)
		{
			int t = moveF(j, st);
			for (int k = 0; k <= 4; k++)
			{
				if (k == st)
					continue;
				setDp(dp[i][k][st], t, dp[i - 1][k][j]);
				setDp(dp[i][st][k], t, dp[i - 1][j][k]);
			}
		}
	}
	int min = INF;
	for (int i = 0; i <= 4; i++)
	{
		int e = dp[vec.size()-1-1][i][vec[vec.size() - 1-1]];
		if (e < min)
			min = e;
		e = dp[vec.size()-1-1][vec[vec.size() - 1-1]][i];
		if (e < min)
			min = e;
	}

	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j <= 4; j++)
	//	{
	//		for (int k = 0; k <= 4; k++)
	//		{
	//			cout << dp[i][j][k] << " ";
	//		}cout << "\n";
	//	}cout << "\n";
	//}cout << "\n";

	return min;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int*** dp;
	vector<int> vec;
	in(N,vec, dp);

	int re = solve(N, vec, dp);
	cout << re << "\n";

	return 0;
}


/*
1 2 1 (=12)
1 2 2 (=12)
1 2 3 (=13)
1 2 4 (=13)

1 3 1 (=13)
1 3 2 (12,32)
1 3 2 1(12)
1 3 2 3(32)
1 3 2 4(24=13)

1 3 3 (=13)



1 2 2 4 0
8

1 0
2

0
0

1 2 1 0
5

1 2 1 2 1 2 0
8

1 3 2 4 1 2 0
14

1 3 2 2 0
8

1 3 2 0
7

1 2 3 1 2 0
11

연속선택
1 3 2 2 2 1 0
10

1 3 2 2 2 4 0
12

1 3 2 2 2 4 2 0
13

1 3 2 2 2 3 0
10

1 3 2 2 1 1 0
10

1 3 2 2 1 1 0
10

1 3 2 4 1 3 2 4 0
20

1 2 3 0
7

4 4 4 0
4

첫두번을 한쪽발로만 밟는 경우
1 2 3 2 0
8

1 2 3 2 1 0
11

*/

// 경우의수 조건이 은근 많음.
/*
#include <iostream>

using namespace std;

int myAbs(int a)
{
	return a >= 0 ? a : -a;
}

bool isL(int a, int b)
{
	if (a % 2 == b % 2)
		return false;
	return true;
}

bool isNear(int a, int n)
{
	if (myAbs(a - n) == 2)
		return false;
	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sum = 0;
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0 << "\n";
		return 0;
	}
	sum += 2;
	int a=0;
	int b=0;
	a = n;
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		if (a == n || b==n)
		{
			sum += 1;
			continue;
		}
		else
		{
			if (a == 0 || b == 0)
			{
				if (a == 0)
					a = n;
				if (b == 0)
					b = n;
				sum += 2;
			}
			else if (isL(a, b))
			{
				if (isNear(a, n))
					a = n;
				else
					b = n;
				sum += 3;
				continue;
			}
			else
			{
				sum += 3;
				int prev = n;
				while (true)
				{
					int nn;
					cin >> nn;
					if (nn == 0)
					{
						cout << sum << "\n";
						return 0;
					}
					if (a == nn || b == nn)
					{
						if (a == nn)
							b = n;
						else
							a = n;
						sum += 1;
						break;
					}
					else if (nn == prev)
					{
						sum += 1;
					}
					else
					{
						a = n;
						b = nn;
						sum += 3;
						break;
					}
					prev = nn;

				}

			}
		}
	}

	cout << sum << "\n";

	return 0;
}
*/
