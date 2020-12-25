#include <iostream>
#include <string>

using namespace std;

int main()
{
	char ch[5][15] = { NULL, };
	for (int i = 0; i < 5; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < str.length(); j++)
			ch[i][j] = str[j];
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (ch[j][i] != NULL)
				cout << ch[j][i];
		}
	}

	return 0;
}