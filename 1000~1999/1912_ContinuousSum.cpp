#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int max = -1000;
	int sum = 0;
	while (n-- > 0)
	{
		int number;
		cin >> number;
		sum += number;
		if (max < sum)
		{
			max = sum;
		}
		if (sum < 0)
		{
			sum = 0;
		}
	}
	cout << max << "\n";
	return 0;
}