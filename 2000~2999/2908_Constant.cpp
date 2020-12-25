#include <iostream>
#include <string>
using namespace std;

void reversePrint(string str);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	if (a.length() == b.length())
	{
		for (int i = a.length() - 1; i >= 0; i--)
		{
			if (a[i] == b[i])
				continue;
			else if (a[i] > b[i])
			{
				reversePrint(a);
				break;
			}
			else if (a[i] < b[i])
			{
				reversePrint(b);
				break;
			}
		}
	}
	else
	{
		if (a.length() > b.length())
		{
			reversePrint(a);

		}
		else if (a.length() < b.length())
		{
			reversePrint(b);
		}
	}

	return 0;
}

void reversePrint(string str)
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		cout << str[i];
	}
	cout << "\n";
}