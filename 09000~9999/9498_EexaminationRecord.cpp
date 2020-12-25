#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	switch (n/10)
	{
	case 10:
	case 9:
		cout << "A\n";
		break;
	case 8:
		cout << "B\n";
		break;
	case 7:
		cout << "C\n";
		break;
	case 6:
		cout << "D\n";
		break;
	default:
		cout << "F\n";
		break;
	}
	return 0;
}