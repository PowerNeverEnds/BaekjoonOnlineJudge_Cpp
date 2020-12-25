#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (true)
	{
		getline(cin, str);
		cout << str << endl;
		if (cin.eof())
			break;
	}
	return 0;
}
/*
	Hello

Baekjoon
   Online Judge
*/