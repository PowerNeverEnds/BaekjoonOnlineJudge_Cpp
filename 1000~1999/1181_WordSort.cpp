#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool upLonger(string op1, string op2);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string t;
	getline(cin, t);
	n = stoi(t);
	string* str = new string[20001];
	for (int i = 0; i < n; i++)
	{
		getline(cin, str[i]);
	}
	sort(&str[0], &str[n]);
	stable_sort(&str[0], &str[n],upLonger);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == str[i - 1])
			continue;
		cout << str[i] << "\n";
	}
	return 0;
}

bool upLonger (string op1, string op2)
{
	return op1.length() < op2.length();
}