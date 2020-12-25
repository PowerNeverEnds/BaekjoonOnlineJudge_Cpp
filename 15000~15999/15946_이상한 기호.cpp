/**
 *    BOJ 15946
 *    - 이상한 기호
 *    author:  phcdream
 *    created: 오전 5:24 2020-12-07
**/

#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	ll A, B;
	cin >> A >> B;
	cout << (A + B) * (A - B) << "\n";

	return 0;
}