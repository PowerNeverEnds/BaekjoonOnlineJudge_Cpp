#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int keypad[26] = {
		2,2,2,
		3,3,3,
		4,4,4,
		5,5,5,
		6,6,6,
		7,7,7,7,
		8,8,8,
		9,9,9,9
	};

	int n;
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if(islower(str[i]))
				str[i] = keypad[str[i] - 'a'] + '0';
			else
				str[i] = keypad[str[i] - 'A'] + '0';
		}
		bool yes = true;
		for (int i = 0; i < str.length()/2; i++)
		{
			if (str[i] != str[str.length() - i - 1])
			{
				yes = false;
				break;
			}
		}
		if (yes)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}