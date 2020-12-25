#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int A, B;
		cin >> A >> B;
		cout << A * B / gcd(A, B) << "\n";
	}
	return 0;
}