#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	
	for (int i = m; i <= n; i++)
	{
		bool isThisPrime = false;
		if (i == 2 || i == 3)
			isThisPrime = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			isThisPrime = true;
			if (i % j == 0)
			{
				isThisPrime = false;
				break;
			}
		}
		if (isThisPrime == true)
			cout << i << "\n";
	}

	return 0;
}