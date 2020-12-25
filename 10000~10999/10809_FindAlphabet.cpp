#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	int alpha[26] = {0, };
	for (int i = 0; i < 26; i++)
		alpha[i] = -1;

	int p;
	for (int i = 0; i < str.length(); i++)
	{
		p = (int)str[i] - (int)'a';
		if(alpha[p]==-1)
			alpha[p]= i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alpha[i] << " ";
	}
	cout << "\n";

	return 0;
}