#include <iostream>
using namespace std;

#define MAX 500000
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	bool* card = new bool[MAX + 1];
	for (int i = 0; i < MAX+1; i++)
	{
		card[i] = true;
	}
	card[0] = false;

	int pCard = 1;
	for (int i = 0; i < n-1; i++)
	{
		while (1)
		{
			if (pCard >= n + 1)
				pCard = pCard-n;
			if (card[pCard] == true)
			{
				card[pCard] = false;
				while (card[pCard++] != true)
				{
					if (pCard >= n + 1)
						pCard = pCard - n;
				}
				break;
			}
			else
				pCard++;
		}
	}
	for (int i = 0; i < n + 1; i++)
	{
		if (card[i] == true)
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}