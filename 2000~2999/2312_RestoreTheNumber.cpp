#include <iostream>
#define MAX 100000/2
using namespace std;

void setPrime(bool* prime, int length);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool* prime = new bool[MAX+1];
	setPrime(prime, MAX+1);

	int n;
	cin >> n;

	while (n-- > 0)
	{
		int number;
		cin >> number;

		for (int i = 2; number != 1; i++)
		{
			if (number % i == 0)
			{
				int count = 0;
				for (;; count++)
				{
					if (number % i == 0) { number /= i; }
					else break;
				}
				cout << i << " " << count << "\n";
			}
		}
	}

	return 0;
}

void setPrime(bool* prime, int length)
{
	for (int i = 0; i < length; i++)
		prime[i] = true;
	prime[1] = false;
	for (int i = 2; i < length; i++)
		if (prime[i] == true)
			for (int j = 2; i * j < length; j++)
				prime[i * j] = false;
}