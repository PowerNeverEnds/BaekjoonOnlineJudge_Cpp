#include <iostream>

using namespace std;

int main()
{
	char c;
	int alpha[26] = { 0, };
	while (c=getchar())
	{
		if (c == EOF)
			break;
		alpha[c - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		cout << alpha[i] << " ";
	cout << "\n";

	return 0;
}