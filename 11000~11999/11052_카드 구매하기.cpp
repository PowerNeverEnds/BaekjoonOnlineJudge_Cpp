#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* P = new int[(ll)N + 1];
	fill(P, P + N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	int* arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		// Á¡È­½Ä
		
		//arr[i] = arr[i - 1]+p[1];
		//arr[i] = arr[i - 2]+p[2];
		//;
		//arr[i] = arr[i - (i - 2)] + p[i - 2];
		//arr[i] = arr[i - (i - 1)] + p[i - 1];
		//arr[i] = arr[0] + p[i];

		for (int j = 1; j <= i; j++)
		{
			if (arr[i] < arr[i - j] + P[j])
			{
				arr[i] = arr[i - j] + P[j];
			}
		}
	}

	cout << arr[N] << "\n";

	return 0;
}