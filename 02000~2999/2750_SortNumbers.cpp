#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[1000] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";

	return 0;
}