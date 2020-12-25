// 추가) 미친방법 https://www.acmicpc.net/source/20108659
// 새로운 방식 b를 나누기
#include <iostream>
#include <map>
typedef unsigned long long ull;
using namespace std;

ull a,b,c;
map<ull, ull> m;
ull mmultiply(int n)
{
	if (m.count(n))
		return m.find(n)->second;
	if (n == 1)
		return a % c;	// % c 추가
	if (n == 2)
	{
		return (a * a)%c;
	}
	if (n % 2 == 0)
		return 
		m[n]=
		(mmultiply(n / 2) * mmultiply(n / 2))%c;
	else
		return 
		m[n]=
		(((mmultiply(n / 2) * mmultiply(n / 2))%c) * a)%c;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c;
	cout<<mmultiply(b)<<"\n";
	return 0;
}

///*
//a = x * n + i
//a * b = x*n+y*n + i + j
//a*b % n = (i+j) % n
//
//dp[i]=a^i
//a=2	0	1	2	4	8	16	32 ...
//dp	1	2	4	16	256 65536...
//mem[i]=dp[i]
//
//*/
//
//#include <iostream>
//#include <cmath>	// cmath 추가
////#define ULL unsigned long long
//typedef unsigned long long ULL;		// 자료형은 typedef
//using namespace std;
//
//// 전체적으로 int->ULL로 자료형 변경
//ULL a, b, c;
//ULL dp[100000];		// 배열길이 추가	// 더 추가
//ULL mem[100000];	// 배열길이 추가
//int main()
//{
//	unsigned long long ull;
//	//ull = ULL(pow(2, 32-1)) * pow(2, 32-1);
//	//cout<<ull%ULL(pow(2, 3-1))<<"\n";
//	//cout << ull % 3<<"\n";
//	//cout << ull << "\n";
//	//cout << ULL(pow(2, 32-1)) << "\n";
//
//
//	//cout << pow(2, 32 - 1) << "\n";
//	//cout << int(double(pow(2, 32 - 1))) << "\n";
//	//cout << int(pow(2, 32 - 1)) << "\n";
//	//cout << (int)ULL(pow(2, 32 - 1)) << "\n";
//	//cout << (int)float(pow(2, 32 - 1)) << "\n";
//
//	cin >> a >> b >> c;
//	dp[0] = 1;
//	dp[1] = a;
//	ULL ie = 1;
//	for (ULL i = 1; i*i <= b; i++)
//	{
//		ie = i + 1;
//		ULL ull;
//		ull = dp[i] * dp[i];
//		ull = ull % c;
//		dp[i + 1] = ull;
//	}
//	for (ULL i = 0; i <= ie; i++)
//	{
//		cout << dp[i] << " ";
//	}cout << "\n";
//	mem[ie] = dp[ie];
//	ULL ibt = pow((ie - 1), 2);
//	for (int i = ie - 1; i >= 0; i--)
//	{
//		if (ibt + pow(i, 2) < b)
//		{
//			mem[i] = ULL(mem[i + 1] * pow(a, dp[i])) % c;
//			ibt += pow(i, 2);
//		}
//		else
//		{
//			mem[i] = mem[i + 1];
//		}
//	}
//
//	for (int i = 0; i <= ie; i++)
//	{
//		cout << mem[i] << " ";
//	}cout << "\n";
//
//	cout << mem[0] << "\n";
//
//	return 0;
//}
