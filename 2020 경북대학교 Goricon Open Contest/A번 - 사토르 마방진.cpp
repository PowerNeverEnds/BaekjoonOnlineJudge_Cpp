#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	char** arr = new char*[n];
	fill(arr, arr + n, nullptr);
	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[n];
		fill(arr[i], arr[i] + n, NULL);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != arr[j][i])
			{
				same = false;
				break;
			}
		}
		if (same == false)
			break;
	}
	if (same == true)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";

	return 0;
}