#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int s = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		s += n * n;
	}
	cout << s % 10 << "\n";

	return 0;
}