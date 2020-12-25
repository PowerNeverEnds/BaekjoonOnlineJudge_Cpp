#include <iostream>
#include <climits>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int max = INT_MIN;
	int min = INT_MAX;
	while (n-- > 0)
	{
		int number;
		cin >> number;
		max = number > max ? number : max;
		min = number < min ? number : min;

	}
	cout << min << " " << max << "\n";

	return 0;
}