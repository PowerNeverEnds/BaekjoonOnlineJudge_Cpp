#include <iostream>
#include <cmath>
using namespace std;

int primeCount(int m, int n);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	while (cin>>m && m!=0)
	{
		n = m * 2;
		cout << primeCount(m+1, n) << "\n";
		
	}
	return 0;
}

int primeCount(int m, int n)
{
	int count = 0;
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
			count++;
	}
	return count;
}