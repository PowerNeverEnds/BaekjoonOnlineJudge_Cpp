#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int m[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int x, y;
	cin >> x >> y;
	int sum = 0;
	for (int i = 0; i < x - 1; i++)
	{
		sum += m[i];
	}
	sum += y;
	cout <<week[sum % 7] << "\n";
	return 0;
}