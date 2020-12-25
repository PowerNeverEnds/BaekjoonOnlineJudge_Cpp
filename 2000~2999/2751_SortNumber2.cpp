#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int *arr = new int[1000000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}