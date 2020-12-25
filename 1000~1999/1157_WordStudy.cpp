#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);

	int arr[27] = { 0, };

	for (int i = 0; i < str.length(); i++)
	{
		if ('a' <= str[i] && str[i] <= 'z')
			arr[str[i] - 'a']++;
		else if ('A' <= str[i] && str[i] <= 'Z')
			arr[str[i] - 'A']++;
	}
	int max = -1;
	bool same = false;
	char alphabat;
	for (int i = 0; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			alphabat = i+'A';
			same = false;
		}
		else if (max == arr[i])
			same = true;
	}
	if (same == true)
		cout << "?" << "\n";
	else
		cout << alphabat << "\n";
	return 0;
}