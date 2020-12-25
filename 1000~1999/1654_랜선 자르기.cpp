#include <iostream>
#include <climits>

typedef unsigned long long ull;

using namespace std;

int arr[10000] = { 0, };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}
	ull l = 0, r = (ull)INT_MAX + 1;
	while (true)
	{
		if (l+1 >= r)
			break;
		ull m = (l + r) / 2;
		ull c = 0;
		for (int i = 0; i < K; i++)
		{
			c += arr[i] / m;
		}
		if (c >= N)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	cout << l << "\n";

	return 0;
}