#include <iostream>

using namespace std;

int myGcd(int a, int b)
{
	int t;
	while (b)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	int A, B;
	cin >> A >> B;
	int AA, BB;
	cin >> AA >> BB;
	int AAA, BBB;
	BBB = B * BB;
	AAA = A * BB + AA * B;
	int iGcd = myGcd(AAA, BBB);

	cout << AAA / iGcd << " " << BBB / iGcd << "\n";

	return 0;
}