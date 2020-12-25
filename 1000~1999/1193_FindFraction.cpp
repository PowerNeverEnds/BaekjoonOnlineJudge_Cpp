#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int up=1, down=1;
	int sum = 0;
	for (int i = 1;; i++)
	{
		if (sum + 1 <= n && n <= sum + i)
		{
			if (i % 2 == 0)
				down = i;
			else
				up = i;
			int plus;
			plus = n - (sum + 1);
			if (i % 2 == 0)
			{
				down -= plus;
				up += plus;
			}
			else
			{
				down += plus;
				up -= plus;
			}
			break;
		}
		sum += i;
	}
	cout << up << "/" << down << "\n";
	return 0;
}
