#include <iostream>

using namespace std;

int main()
{
	int N, a, b;
	cin >> N >> a >> b;

	int i;
	for(i = 1;;i++)
	{
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		if (a == b)
			break;
	}
	cout << i << "\n";

	return 0;
}