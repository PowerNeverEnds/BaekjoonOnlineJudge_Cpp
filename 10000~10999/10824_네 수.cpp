#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str[2];
	string t;
	for (int i = 0; i < 2; i++)
	{
		cin >> str[i];
		cin >> t;
		str[i] += t;
	}

	cout << stoll(str[0]) + stoll(str[1]) << "\n";

	return 0;
}