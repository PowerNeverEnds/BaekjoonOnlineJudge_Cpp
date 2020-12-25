#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	int count = 0;
	while (n-- > 0)
	{
		string str;
		getline(cin, str);
		bool gwc[27] = { 0, };	// GroupWordChecker, 0 == false
		int i;
		for (i = 0; i < str.length(); i++)
		{
			if (gwc[str[i] - 'a'] == true)
			{
				if (str[i] != str[i - 1])
				{
					break;
				}
			}
			gwc[str[i] - 'a'] = true;
		}
		if (i == str.length())
			count++;
	}
	cout << count << "\n";

	return 0;
}