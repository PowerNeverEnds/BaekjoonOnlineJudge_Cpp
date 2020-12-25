#include <iostream>
using namespace std;

bool hanSoo(int& n, int m, int& div);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int count=0;
	for (int i = 1; i <= n; i++)
	{
		int m=0;
		int n = i;
		int div;
		if (hanSoo(n, m, div))
		{
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}

// n은 참조, div는 맨 앞 두수 차이
// 3589 -> 358,9 -> 35,8 -> 3,5 순으로 재귀함수 호출되어 맨앞 숫자부터 비교
// div = -2 가되고, return true;
// 이후 재귀함수 return 하면서, n-m이 div 랑 비교하면서, 다르면 이후엔 계속 false 리턴. 
bool hanSoo(int& n, int m, int& div)
{
	if (n < 10)
	{
		div = n - m;
		return true;
	}
	else
	{
		m = n % 10;
		n /= 10;
		if (hanSoo(n, m, div) && n - m == div )	// 이전까지 true 이면서, 이번자리에서 n - m == div일때.
		{
			n = m;
			return true;
		}
		else
		{
			n = m;
			return false;
		}
	}
}