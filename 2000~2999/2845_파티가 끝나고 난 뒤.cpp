#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int L, P;
	cin >> L >> P;
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		cout << n - L * P << " ";
	}

	return 0;
}