#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		int sum = 0;
		int cnt = 0;
		if (a == cnt)
			;
		else if (a <= (cnt += 1))
			sum += 500;
		else if (a <= (cnt += 2))
			sum += 300;
		else if (a <= (cnt += 3))
			sum += 200;
		else if (a <= (cnt += 4))
			sum += 50;
		else if (a <= (cnt += 5))
			sum += 30;
		else if (a <= (cnt += 6))
			sum += 10;
		
		cnt = 0;
		if (b == cnt)
			;
			else if (b <= (cnt += 1))
			sum += 512;
			else if (b <= (cnt += 2))
			sum += 256;
			else if (b <= (cnt += 4))
			sum += 128;
			else if (b <= (cnt += 8))
			sum += 64;
			else if (b <= (cnt += 16))
			sum += 32;	

		cout << sum*10000 << "\n";

	}

	return 0;
}