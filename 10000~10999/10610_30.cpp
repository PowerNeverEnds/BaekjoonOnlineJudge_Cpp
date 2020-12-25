#include <iostream>

#define DIV 3

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char ch;
	int n;
	int sum = 0;
	int numCnt[10] = { 0, };
	while (true)
	{
		cin >> ch;
		if (cin.eof())
			break;
		n = ch - '0';
		sum = (sum + n) % 3;
		numCnt[n]++;
	}

	if (sum != 0 || numCnt[0] == 0)
	{
		cout << "-1" << "\n";
	}
	else
	{
		for (int i = 9; i >= 0; i--)
			for (int j = 0; j < numCnt[i]; j++)
				cout << i;
	}

	return 0;
}