/**
 *    BOJ 1834
 *    - �������� ���� ���� ��
 *    author:  phcdream
 *    created: ���� 6:26 2020-12-07
**/

#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	ll n;
	cin >> n;
	ll sum = 0;
	for (ll i = 1; i < n; i++)
	{
		sum += i * n + i;
	}

	cout << sum << "\n";

	return 0;
}