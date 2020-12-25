#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool upToDown(char a, char b);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);

	sort(&str[0], &str[str.length()],upToDown);

	cout << str << "\n";
}

bool upToDown(char a, char b)
{
	return a > b;
}