#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int sum = 1;
	for (int i = 0; i < n; i++)
	{
		sum += i * 6;
		if (n <= sum)
		{
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}