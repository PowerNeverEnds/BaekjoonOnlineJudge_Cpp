#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int h, w, n;
		cin >> h >> w >> n;
		cout << (n - 1) % h + 1;
		if (((n - 1) / h + 1) < 10)
			cout << "0";
		cout << (n - 1) / h + 1 << "\n";
	}
}