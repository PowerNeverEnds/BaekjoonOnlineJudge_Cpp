#include <iostream>
#include <string>
using namespace std;

bool findBalance(string str);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	while (getline(cin, str) && str != ".")
	{
		if (findBalance(str) == true)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
	return 0;
}

bool findBalance(string str)
{

	int bigBracket = 0;
	int smallBracket = 0;
	char bracket[102] = { 0, };
	int pBracket = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '[')
		{
			bracket[pBracket++] = str[i];
			bigBracket++;
		}
		if (str[i] == ']')
		{
			if (bracket[--pBracket] != '[')
				return false;
			bigBracket--;
		}
		if (str[i] == '(')
		{
			bracket[pBracket++] = str[i];
			smallBracket++;
		}
		if (str[i] == ')')
		{
			if (bracket[--pBracket] != '(')
				return false;
			smallBracket--;
		}
		if (bigBracket < 0 || smallBracket < 0)
			return false;
	}
	if (bigBracket == 0 && smallBracket == 0)
		return true;
	else
		return false;
}