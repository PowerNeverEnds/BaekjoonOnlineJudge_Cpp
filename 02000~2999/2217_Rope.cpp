#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int* arr = new int[100000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	sort(&arr[0], &arr[n]);

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = arr[i] * (n - i);
		if (max < sum)
			max = sum;
	}
	cout << max << "\n";

	return 0;
}