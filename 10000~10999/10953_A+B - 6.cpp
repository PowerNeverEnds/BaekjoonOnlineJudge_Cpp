#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		//char a, o, b;
		int a,b;
		char o;
		//cin >> a;
		//cin >> o;
		//cin >> b;
		cin >> a >> o >> b;
		//cout << (a - '0') + (b - '0') << "\n";
		cout << a + b << "\n";
	}

	return 0;
}