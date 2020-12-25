/**
 *    BOJ 1964
 *    - 오각형, 오각형, 오각형…
 *    author:  phcdream
 *    created: 오후 11:48 2020-12-06
**/

#include <iostream>

typedef long long ll;

#define DIV ((int)45678)

using namespace std;

int main()
{
	int N;
	cin >> N;
	ll sum = 5;
	ll prev = 4;
	for (int i = 2; i <= N; i++)
	{
		prev += 3;
		sum +=prev;
		sum %= DIV;
	}

	cout << sum << "\n";

	return 0;
}