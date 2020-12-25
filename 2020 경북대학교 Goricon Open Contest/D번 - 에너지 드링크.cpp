#include <iostream>
#include <iomanip>

typedef unsigned long long ull;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	ull sum = 0;
	ull max = 0;

	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		sum += e;
		max = e > max ? e : max;
	}
	sum -= max;
	double a;
	a = (sum / 2.0) + max;
	setprecision(5);
	cout << fixed << a << "\n";

	return 0;
}