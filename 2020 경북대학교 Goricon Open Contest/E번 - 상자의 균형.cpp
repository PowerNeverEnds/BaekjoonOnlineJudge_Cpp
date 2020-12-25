#include <iostream>

typedef long long ll;

using namespace std;

double arr[200002][2];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, L;
	cin >> n >> L;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0];

	//arr[(ull)n-1][1] = arr[(ull)n-1][0];
	for (int i = n-1; i >= 0; i--)
	{
		arr[i][1] = arr[i + 1][1] + arr[i][0];
	}

	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i][0] << " " << arr[i][1] << "\n";
	//}

	for (int i = 0; i < n-1; i++)
	{
		double m = (double)arr[i + 1][1] / ((ll)n - i - 1);
		//cout << i << " " << m <<" "<<arr[i][0]<<" "<<L<< "\n";
		if (m <= arr[i][0] - L || arr[i][0] + L <= m)
		{
			cout << "unstable" << "\n";
			return 0;
		}
	}

	cout << "stable" << "\n";
	return 0;
}