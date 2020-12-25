#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int t = i;
		int sum = i;
		while (t != 0)
		{
			sum += t % 10;
			t /= 10;
		}
		if (sum == n)
		{
			cout << i << "\n";
			break;
		}
	}
	if (i == n)
		cout << 0 << "\n";
}