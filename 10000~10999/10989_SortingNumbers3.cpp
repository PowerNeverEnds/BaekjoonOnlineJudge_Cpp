#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int *number = new int[10001];
	for (int i = 0; i < 10001; i++)
	{
		number[i] = 0;
	}
	int n;
	cin >> n;
	while (n-- > 0)
	{
		int k;
		cin >> k;
		number[k]++;
	}
	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < number[i]; j++)
			cout << i << "\n";
	}
	return 0;
}