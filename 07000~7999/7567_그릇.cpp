#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
	string str;
	cin >> str;
	int h = 0;
	h += 10;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[(ll)i - 1] != str[i])
			h += 5;
		h += 5;
	}
	cout << h << "\n";

	return 0;
}