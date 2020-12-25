#include <iostream>
#include <string>
using namespace std;

bool validPS(string str);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	while (n-- > 0)
	{
		string str;
		getline(cin, str);
		switch (validPS(str))
		{
		case true:
			cout << "YES" << "\n";
			break;
		case false:
			cout << "NO" << "\n";
			break;
		}
	}
	return 0;
}
bool validPS(string str)
{
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')' && count > 0)
			count--;
		else
			return false;
	}
	if (count == 0)
		return true;
	else
		return false;
}