#include <iostream>
using namespace std;

int leapYear(int n);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << leapYear(n) << "\n";
}

int leapYear(int n)
{
	if (n % 4 == 0)
	{
		if (n % 100 != 0 || n%400==0)
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}