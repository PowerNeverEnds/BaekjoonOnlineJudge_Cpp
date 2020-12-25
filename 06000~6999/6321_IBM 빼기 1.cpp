#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		for (auto& e : str)
			e = (e - 'A' + 1) % 26 + 'A';
		cout << "String #" << i << "\n";
		cout << str << "\n";
		cout << "\n";
	}

	return 0;
}