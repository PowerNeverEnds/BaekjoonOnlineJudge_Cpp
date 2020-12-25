#include <iostream>

using namespace std;

int defRev(int n)
{
	int nN = 0;
	while (n)
	{
		nN = nN * 10 + n % 10;
		n /= 10;
	}
	return nN;
}

int main()
{
	int X, Y;
	cin >> X >> Y;

	//cout << defRev(X) << "\n";

	cout << defRev(defRev(X) + defRev(Y)) << "\n";

	return 0;
}