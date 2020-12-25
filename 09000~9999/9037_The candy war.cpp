/**
 *    BOJ 9037
 *    - The candy war
 *    author:  phcdream
 *    created: ¿ÀÈÄ 10:27 2020-12-07
**/

#include <iostream>

typedef long long ll;

using namespace std;

bool isSame(int N, int* arr)
{
	int zero = arr[0];
	for (int i = 0; i < N; i++)
	{
		if (zero != arr[i])
			return false;
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int* arr = new int[(ll)N];
		fill(arr, arr + N, 0);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		for (int i = 0; i < N; i++)
			if (arr[i] % 2 == 1)
				arr[i]++;

		int cnt = 0;
		while (true)
		{
			//for (int i = 0; i < N; i++)
			//	cout << arr[i] << " ";
			//cout << "\n";
			if (isSame(N, arr))
				break;
			int t = arr[N - 1];
			for (int j = N - 1; j >= 1; j--)
			{
				arr[j] /= 2;
				arr[j] += arr[j - 1] / 2;
			}
			arr[0] /= 2;
			arr[0] += t / 2;

			for (int i = 0; i < N; i++)
				if (arr[i] % 2 == 1)
					arr[i]++;
			cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}