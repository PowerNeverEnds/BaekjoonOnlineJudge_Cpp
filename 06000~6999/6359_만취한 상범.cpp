#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		bool* arr = new bool[(ll)n+1];
		fill(arr, arr + n + 1, false);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
			{
				arr[j] = !arr[j];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] == true)
				cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}