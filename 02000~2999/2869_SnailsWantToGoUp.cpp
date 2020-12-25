#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, v;
	cin >> a >> b >> v;

	if (a > v)
		cout << 1 << "\n";
	else
	{
		if ((v - a) % (a - b) == 0)
			cout << (v - a) / (a - b) + 1 << "\n";
		else
			cout << (v - a) / (a - b) + 2 << "\n";
	}

	return 0;
}