#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int *arr = new int[n+1];
	int p = 0;
	while (n-- > 0)
	{
		cin >> arr[p];
		if (arr[p] == 0)
			p--;
		else
			p++;
	}
	int sum = 0;
	for (int i = 0; i < p; i++)
		sum += arr[i];
	cout << sum << "\n";
	return 0;
}