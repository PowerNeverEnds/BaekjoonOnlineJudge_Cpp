#include <iostream>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	int ab, bc;
	ab = B - A - 1;
	bc = C - B - 1;
	
	cout << (ab > bc ? ab : bc) << "\n";

	return 0;
}