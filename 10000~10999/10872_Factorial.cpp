#include <iostream>
using namespace std;

int f(int n);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << f(n) << "\n";

	return 0;
}
int f(int n)
{
	if (n == 0)
		return 1;
	else
		return n * f(n - 1);
}