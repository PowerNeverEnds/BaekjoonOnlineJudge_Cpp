#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int F;
	cin >> F;
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		int t = N / 100 * 100;
		t += i;
		if (t % F == 0)
			break;
	}
	if (i < 10)
		cout << "0";
	cout << i << "\n";

	return 0;
}