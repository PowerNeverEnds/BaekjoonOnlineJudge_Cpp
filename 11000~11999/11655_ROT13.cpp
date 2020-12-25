#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	for (auto& e : str)
	{
		if (isalpha(e))
		{
			if (islower(e))
			{
				e = ((e - 'a') + 13) % 26 + 'a';
			}
			else if (isupper(e))
			{
				e = ((e - 'A') + 13) % 26 + 'A';
			}
		}
	}

	cout << str << "\n";


	return 0;
}