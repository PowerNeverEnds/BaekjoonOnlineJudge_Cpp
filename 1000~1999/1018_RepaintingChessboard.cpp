#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	bool arr[50][50] = { 0, };
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = str[j]=='W'?true:false;
		}
	}
	int sameMaxValue = 0;
	for (int i = 0; i <= n-8; i++)
	{
		for (int j = 0; j <= m-8; j++)
		{
			int count = 0;	// 격자 같은 무늬(값) 카운트
			for (int y = i; y < i + 8; y++)
			{
				for (int x = j; x < j + 8; x++)
				{
					//	x+y값은 짝홀이 격자처럼이뤄짐
					// 0123
					// 1234
					// 2345
					if (arr[y][x] == (x + y) % 2)
					{
						count++;
					}
				}
			}
			count = abs(count - 32);	// count가 32에서 멀수록, 0이나 64에 가까울수록 맞는 조각이 많음.
			count += 32;	// 최대값 64로 할려고
			sameMaxValue = count > sameMaxValue ? count : sameMaxValue;
		}
	}
	cout << 64 - sameMaxValue << "\n";
	return 0;
}