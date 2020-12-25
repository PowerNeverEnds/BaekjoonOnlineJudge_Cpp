#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	while (true)
	{
		getline(cin,a);
		cout << a << endl;
		if (cin.eof())
			break;
	}
	return 0;
}