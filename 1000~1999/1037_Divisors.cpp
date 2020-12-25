#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	unsigned int max = 1;
	unsigned int min = 1000001;
	while (n-- > 0)
	{
		int number;
		cin >> number;
		max = number>max ? number : max;
		min = number<min ? number:min;
	}

	cout << max * min << "\n";

	return 0;
}