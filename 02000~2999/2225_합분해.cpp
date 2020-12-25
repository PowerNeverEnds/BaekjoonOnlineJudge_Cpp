#include <iostream>

typedef long long ll;

#define DIV (int)1e9

using namespace std;

int main()
{
	ll N, K;
	cin >> N >> K;
	ll* arr = new ll[(ll)N + 1];
	fill(arr, arr + N + 1, 1);

	for (int j = 1; j < K; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			arr[i] += arr[i - 1];
			arr[i] %= DIV;
		}
		//for (int i = 0; i <= N; i++)
		//	cout << arr[i] << " ";
		//cout << "\n";
	}


	cout << arr[N] << "\n";

	return 0;
}

/*
20 2
21

5 3
21

5 4
56

*/