#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int n;
	cin >> n;
	long long int arr[1000] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(&arr[0], &arr[n]);


	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (arr[i] * (n-i));
	}

	cout << sum << "\n";

	return 0;
}
/*
3
1000000000
1000000000
1000000000

*/