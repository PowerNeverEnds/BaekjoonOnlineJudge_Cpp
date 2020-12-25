#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int count = 0;
	int number = 1;
	for (int i = 1; i <= n; i++)
	{
		number *= i;
		while (number % 10 == 0)
		{
			number /= 10;
			count++;
		}
		number %= 1000000;
	}
	cout << count << "\n";

	return 0;
}