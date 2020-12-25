#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int t = n;
	int count = 0;
	do
	{
		t = ((t % 10) * 10) + (((t % 10) + (t / 10)) % 10);
		count++;
	} while (t != n);

	cout << count << "\n";

	return 0;
}