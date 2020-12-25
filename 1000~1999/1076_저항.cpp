#include <iostream>
#include <string>

typedef unsigned long long ull;

using namespace std;

int main()
{
	string color[10] = {
		"black",
"brown",
"red",
"orange",
"yellow",
"green",
"blue",
"violet",
"grey",
"white"
	};
	string val1, val2;
	string multi;
	ull num = 0;
	cin >> val1 >> val2 >> multi;
	for (int i = 0; i < 10; i++)
	{
		if (val1 == color[i])
			num += i * 10;
		if (val2 == color[i])
			num += i;
	}
	for (int i = 0; i < 10; i++)
	{
		if (multi == color[i])
			break;
		num *= 10;
	}
	cout << num << "\n";

	return 0;
}