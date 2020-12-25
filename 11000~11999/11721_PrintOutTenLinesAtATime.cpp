#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		if ((i + 1) % 10 == 0)
			cout << "\n";
	}

	return 0;
}