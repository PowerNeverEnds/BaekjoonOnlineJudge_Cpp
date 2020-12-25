#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	int arr[2001] = { 0, };
	int cnt = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (cnt == 1001)
			break;
		for (int j = 0; j < i; j++)
		{
			if (cnt == 1001)
				break;
			arr[++cnt] = i;
		}
	}
	int sum = 0;
	for (int i = A; i <= B; i++)
	{
		sum += arr[i];
	}
	cout << sum << "\n";

	return 0;
}