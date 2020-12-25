#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int s = 0;
	for (int i = 0; i < 8; i++)
	{
		int e;
		cin >> e;
		s = s * 10 + e;
	}
	if (s == 12345678)
	{
		cout << "ascending" << "\n";
	}
	else if (s == 87654321)
	{
		cout << "descending" << "\n";
	}
	else
	{
		cout << "mixed" << "\n";
	}

	return 0;
}