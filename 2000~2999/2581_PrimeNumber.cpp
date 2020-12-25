#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool* arr = new bool[10001];
	
	for (int i = 0; i < 10001; i++)
	{
		arr[i] = true;
	}
	arr[0] = arr[1] = false;
	for (int i = 2; i < 10001; i++)
	{
		if (arr[i] == true)
		{
			for (int j = i+i; j < 10001; j += i)
			{
				arr[j] = false;
			}
		}
	}
	int m, n;
	cin >> m >> n;
	int min = 10001;
	int sum = 0;
	for (int i = m; i <= n; i++)
	{
		if (arr[i] == true)
		{
			sum += i;
			if (i < min)
			{
				min = i;
			}
		}
	}
	if (sum == 0)
		cout << -1 << "\n";
	else
		cout << sum << "\n" << min << "\n";

	return 0;
}