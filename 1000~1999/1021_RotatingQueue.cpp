#include <iostream>
#include <deque>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	deque<int> dQ;
	for (int i = 1; i <= n; i++)
	{
		dQ.push_back(i);
	}

	int sum = 0;
	while (m-- > 0)
	{
		int number;
		cin >> number;
		int count = 0;
		while (1)
		{
			if (number == dQ.front())
			{
				count = count<(dQ.size()-count)?count:(dQ.size()-count);
				dQ.pop_front();
				break;
			}
			else
			{
				dQ.push_back(dQ.front());
				dQ.pop_front();
				count++;
			}
		}
		sum += count;
	}
	cout << sum << "\n";

	return 0;
}