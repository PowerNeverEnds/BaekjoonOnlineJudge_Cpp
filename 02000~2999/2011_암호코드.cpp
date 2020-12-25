#include <iostream>
#include <string>

typedef long long ll;

#define DIV ((int)1e6)

using namespace std;

int main()
{
	string str = "";
	cin >> str;

	int sLen = 0;
	sLen = (int)str.length();

	int** dp = new int* [(ll)sLen];
	fill(dp, dp + sLen, nullptr);
	for (int i = 0; i < sLen; i++)
	{
		dp[i] = new int[2];
		fill(dp[i], dp[i] + 2, 0);
	}

	{
		if (str[0] != '0')
			dp[0][0] = 1;
		else
			dp[0][0] = 0;
		dp[0][1] = 0;
		//dp[1][0] = 1;	//C6386 버퍼 오버런이 발생했습니다. 
	}
	for (int i = 1; i < sLen; i++)
	{
		if (i > 1)
			break;
		if (str[i] != '0')
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];	//C6386 버퍼 오버런 
		else
			dp[i][0] = 0;
		string tStr = str.substr(0, 2);
		//cout << tStr << "\n";
		if (stoi(tStr) <= 26 && stoi(tStr) != 0)
		{
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];

		}
	}

	for (int i = 2; i < sLen; i++)
	{
		int t;
		string tStr;
		tStr = str[(ll)i - 1];
		tStr += str[i];
		t = stoi(tStr);
		//cout << t << "\n";
		if (10 <= t && t <= 26)//&& t != 0)
		{
			dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
			dp[i][1] %= DIV;
		}
		if (str[i] != '0')
		{
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][0] %= DIV;
		}
	}
	//for (int i = 0; i < sLen; i++)
	//{
	//	cout << dp[i][0] << " " << dp[i][1] << "\n";
	//}

	cout << (dp[sLen - 1][0] + dp[sLen - 1][1]) % DIV << "\n";

	delete[] dp;

	return 0;
}

/*
01

10

100

101

1010

0011000

0011000111



*/