#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str == "0")
	{
		cout << 0 << "\n";
		return 0;
	}
	
	for (int i = 0; i < str.length(); i++)
	{
		string out = "";
		int n = str[i] - '0';
		int j = 0;
		for (j = 0; n; j++)
		{
			out = to_string(n % 2) + out;
			n /= 2;
		}
		if (i != 0)
			for (j; j < 3; j++)
				out = '0' + out;
		cout << out;
	}

	return 0;
}