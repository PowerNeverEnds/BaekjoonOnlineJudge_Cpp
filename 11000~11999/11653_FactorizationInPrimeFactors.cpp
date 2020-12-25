#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int i = 2;
	while(i <= n)
	{
		if (n % i == 0)
		{
			cout << i << "\n";
			n /= i;
			continue;
		}
		else
			i++;
	}

	return 0;
}