#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	int sum = a * b * c;
	int arr[10] = { 0, };
	while (sum!=0)
	{
		arr[sum % 10]++;
		sum /= 10;
	}
	for (int i = 0; i <= 9; i++)
	{
		cout << arr[i] << "\n";
	}
}