#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int B;
	cin >> B;
	int x = 1;
	int sum = 0;
	for (int i = (int)str.length() - 1; i >= 0; i--)
	{
		if (isalpha(str[i]))
		{
			sum += (str[i] - 'A' + 10) * x;
		}
		else
			sum += (str[i] - '0') * x;
		x *= B;
	}

	cout << sum << "\n";

	return 0;
}