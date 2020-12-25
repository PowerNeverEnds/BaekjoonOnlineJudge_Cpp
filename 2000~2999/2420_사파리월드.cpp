#include <iostream>

typedef long long ll;

using namespace std;

ll myAbs(ll a, ll b)
{
	return a > b ? a - b : b - a;
}

int main()
{
	ll N, M;
	cin >> N >> M;

	cout << myAbs(N, M) << "\n";

	return 0;
}