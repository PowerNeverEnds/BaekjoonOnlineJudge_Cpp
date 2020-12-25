/**
 *    BOJ 13241
 *    - 최소공배수
 *    author:  phcdream
 *    created: 오전 3:52 2020-12-06
**/

#include <iostream>

typedef long long ll;

using namespace std;

int gcd(int A, int B)
{
	int t;
	while (B)
	{
		t = B;
		B = A % B;
		A = t;
	}
	return A;
}

int main()
{
	int A, B;
	cin >> A >> B;
	ll sum = gcd(A, B);
	cout << (ll)A * B / sum << "\n";

	return 0;
}