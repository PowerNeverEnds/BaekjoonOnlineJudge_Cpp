#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int r;
		string s;
		cin >> r;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < r; j++)
			{
				cout << s[i];
			}
		}
		cout << "\n";
	}
	return 0;
}