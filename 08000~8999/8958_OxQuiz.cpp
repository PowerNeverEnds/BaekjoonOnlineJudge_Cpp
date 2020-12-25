#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n-- > 0)
	{
		string str;
		cin >> str;
		int count = 0;
		int sum = 0;
		if (str[0] == 'O')
		{
			count++;
			sum += count;
		}
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == 'O')
			{
				count++;
				sum += count;
			}
			else
			{
				count = 0;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}