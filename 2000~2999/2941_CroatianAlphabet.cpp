#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string croAlpha[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

	string str;
	getline(cin, str);
	
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int key = 0;
		for (int j = 0; j < 8; j++)
		{
			if (croAlpha[j][0] == str[i] && key == 0)
			{
				for (int k = 0; k < croAlpha[j].length(); k++)
				{
					if (croAlpha[j][k] != str[i + k]) {
						key = 0;
						break;
					}
					else
						key = 1;
				}
				if (key == 1)
				{
					count++;
					i += croAlpha[j].length() - 1;
					break;
				}
			}
		}
		if (key == 0)	// anyCroatianAlphabet match(Common English Alphabet)
			count++;
	}
	cout << count << "\n";
	return 0;
}