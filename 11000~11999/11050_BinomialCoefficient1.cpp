#include <iostream>
using namespace std;

int fact(int n);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	cout << (fact(n) / (fact(n - k) * fact(k))) << "\n";

	return 0;
}

int fact(int n)
{
	int sum = 1;
	if (n == 0)
		return 1;
	for (int i = n; i >= 1; i--)
	{
		sum *= i;
	}
	return sum;
}