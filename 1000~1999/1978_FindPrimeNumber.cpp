#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		if (number == 1)
			continue;
		bool isThisPrime = true;
		for (int j = 2; j <= number / 2; j++)
		{
			if (number % j == 0)
				isThisPrime = false;
		}
		if (isThisPrime == true)
			count++;
	}
	cout << count << "\n";
	return 0;
}