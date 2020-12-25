/*
nCr = n-1Cr-1 + n-1Cr
nCr = n!/r!(n-r)!
nCn = n!/n!(n-n)! = 0! = 1
nC1 = n!/1!(n-1)! = n*(n-1)*(n-2)...*1/(n-1)*(n-2)...*1 = n
nC0 = n!/0!(n-0)! = n!/n! = 1

위에꺼 아님
페르마의 소정리, 곱셈의 역원
a^(p-1)=1(mod m) p는 소수
a*a^(p-2)=1,	a 의 역원 a^(p-2)
a^(p-2)=1/a
nCr = n!/r!(n-r)!
	= n!*(r!(n-r)!)^(p-2)

*/

#include <iostream>
typedef unsigned long long ull;
#define P 1000000007
using namespace std;

ull dp(ull a, ull b)
{
	ull r = 1;
	while (b > 0)
	{
		if (b % 2 != 0)
		{
			r = (r * a) % P;
			b -= 1;
		}
		a = (a * a) % P;
		b /= 2;
	}
	return r;
}
ull fac[4000001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	fac[0] = 1;
	for (int i = 1; i < 4000000; i++)
	{
		fac[i] = (fac[i - 1] * i) % P;
	}
	int n, k;
	cin >> n >> k;
	//cout << fac[n] << " " << fac[k] << " " << fac[n - k] << "\n";
	//cout << dp((fac[k]) % P, P - 2) % P << "\n";
	//cout << dp((fac[n - k]) % P, P - 2) % P << "\n";
	ull a, b, c;
	a = (fac[k] * fac[n - k]) % P;
	b = dp( a , P - 2) % P;
	c = (fac[n]*b) % P;
	//cout << a << " " << b << " ";
	cout<< c << "\n";
//	cout << (dp((fac[k]) % P, P - 2) % P) * (dp((fac[n - k]) % P, P - 2) % P)%P << "\n";
//	cout<<fac[n] * dp((fac[k] * fac[n - k])%P, P - 2)<<"\n";

	return 0;
}