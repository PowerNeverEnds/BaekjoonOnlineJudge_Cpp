#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	while (true)
	{
		getline(cin, str);
		if (str=="END")
			break;
		for (int i = str.length() - 1; i >= 0; i--)
		{
			cout << str[i];
		}
		cout << "\n";
	}
	return 0;
}