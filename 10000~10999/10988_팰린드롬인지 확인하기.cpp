#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != str[str.length() - i - 1])
		{
			cout << 0 << "\n";
			return 0;
		}
	}

	cout << 1 << "\n";

	return 0;
}