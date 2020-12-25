#include <iostream>

typedef long long ll;

using namespace std;

ll myGcd(ll a, ll b)
{
	ll t;
	while (b)
	{
		t = a;
		a = b;
		b = t % b;
	}
	return a;
}

int main()
{
	ll A, B;
	cin >> A >> B;

	//cout << myGcd(A, B) << "\n";
	ll n;
	n = myGcd(A, B);
	for (int i = 0; i < n; i++)
	{
		cout << "1";
	}

	return 0;
}

/*
3 4
1
3 6
111
3 5
1
2 4
11
2 6
11
4 6
11
3 6
111




*/