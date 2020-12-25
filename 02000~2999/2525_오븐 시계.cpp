#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	int C;
	cin >> C;
	B += C;
	A = (A + (B / 60)) % 24;
	B %= 60;

	cout << A << " " << B << "\n";

	return 0;
}