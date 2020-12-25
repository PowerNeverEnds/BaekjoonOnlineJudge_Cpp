#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		int r = 0;
		int t = n;
		while (t)
		{
			r = r * 10 + t % 10;
			t /= 10;
		}

		if (n == r)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
	return 0;
}