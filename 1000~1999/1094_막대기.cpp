#include <iostream>

using namespace std;

int main()
{
	int cnt[7] = { 0, };
	int val[7] = { 1, };
	for (int i = 1; i <= 6; i++)
		val[i] = val[i - 1] * 2;

	int X;
	cin >> X;

	cnt[6] = 1;
	while (true)
	{
		int sum = 0;
		for (int i = 0; i <= 6; i++)
		{
			sum += cnt[i] * val[i];
			//cout << val[i] << " "<<cnt[i] << "\n";
		}
		//cout << sum << "\n";
		int min = 0;
		if (sum == X)
			break;
		if (sum > X)
		{
			for (int i = 0; i <= 6; i++)
				if (cnt[i] != 0)
				{
					cnt[i]--;
					min = i - 1;
					cnt[min] += 2;
					break;
				}
			if (sum - val[min] >= X)
				cnt[min]--;
		}
	}

	int c = 0;
	for (int i = 0; i <= 6; i++)
		c += cnt[i];
	
	cout << c << "\n";

	return 0;
}