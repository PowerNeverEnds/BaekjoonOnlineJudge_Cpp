#include <iostream>

typedef long long ll;

using namespace std;

int myGcd(int a, int b)
{
	int t;
	while (b)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		fill(arr, arr + n, 0);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		ll sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				sum+=myGcd(arr[i], arr[j]);
		cout << sum << "\n";

		delete[] arr;
	}
	return 0;
}