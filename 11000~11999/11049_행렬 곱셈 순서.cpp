#include <iostream>

typedef long long ll;

#define INF ((ll)1e12)

using namespace std;

struct MyStruct
{
	ll a;
	ll b;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	MyStruct* arr = new MyStruct[(ll)N + 1];
	for (int i = 1; i <= N; i++)
	{
		ll a, b;
		cin >> a >> b;
		arr[i] = MyStruct({ a,b });
	}

	ll** dp = new ll*[(ll)N + 1];
	fill(dp, dp + N + 1, nullptr);
	for (int i = 0; i < N+1; i++)
	{
		dp[i] = new ll[(ll)N + 1];
		fill(dp[i], dp[i] + N + 1, INF);
	}

	if(N>=2)
	{
		dp[1][1] = 0;
		dp[2][1] = arr[1].a * arr[2].a * arr[2].b;
		dp[2][2] = 0;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			//if (j == 1)
			//{
			//	dp[i][1] = arr[i-1].a * arr[i].a * arr[i].b;
			//	//continue;
			//}
			ll min = INF;
			if (j <= 2)
				min = 0;
			for (int k = 1; k < j-1; k++)
			{
				//cout << dp[j - 1][k] << " " << min << "\n";
				if (dp[j - 1][k] < min)
				{
					min = dp[j - 1][k];
					//cout << min << "\n";
				}
			}
			ll t = 0;
			for (int k = j+1; k < i; k++)
			{
				t += arr[j].a * arr[k].a * arr[k].b;
			}
			t += arr[j].a * arr[i].a * arr[i].b;
			ll merge = 0;
			if (j != 1)
			{
				//cout << arr[1].a << " " << arr[j].a << " " << arr[i].b << "\n";
				merge = arr[1].a * arr[j].a * arr[i].b;
			}
			//cout << i << " " << j << " " << min << " " << t << " " << merge << "\n";
			dp[i][j] = min + t + merge;
			if (dp[i][j] > INF)
				dp[i][j] = INF;
		}
	}

	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j <= N; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}cout << "\n";
	//}

	ll min = INF;
	for (int i = 1; i <= N-1; i++)
	{
		if (dp[N][i] < min)
			min = dp[N][i];
	}

	if (N == 1)
		cout << 0 << "\n";
	else
		cout << min << "\n";

	return 0;
}


/*
0
30 0
90  0


4
5 3
3 2
2 6
6 4


abc

abc
a bc

abcd

abcd

abcd	ab ac cd	30 60 120	210
a bcd	bc bd ad	36 72 60	168
ab cd	ab cd ad	30 48 40	118
abc d

8

1 100

100 1

1 100

100 1

1 100

100 1

1 100

100 1


1
5 3


*/