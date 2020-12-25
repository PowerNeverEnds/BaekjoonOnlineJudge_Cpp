#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << a + b << "\n";
	}
}