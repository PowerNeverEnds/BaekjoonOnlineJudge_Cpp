#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

ll arr[250000] = { 0, };
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll N, M, B;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i * M + j];
		}
	}
	//for (int i = 0; i < N * M; i++)
	//{
	//	cout << arr[i] << " ";
	//	if (i % M == M-1)
	//		cout << "\n";
	//}

	sort(arr, arr + N * M, [](auto a, auto b) {
		return a < b;
		});

	ll mid = arr[N * M * 2 / 3];
	ll requiredBlock = 0;
	while (true)
	{
		requiredBlock = 0;
		for (int i = 0; i < N * M; i++)
		{
			requiredBlock += mid - arr[i];
		}
		if (requiredBlock <= B)
		{
			break;
		}
		else
		{
			mid--;
		}
	}
	ll time = 0;
	for (int i = 0; i < N * M; i++)
	{
		time += mid > arr[i] ? mid - arr[i] : (arr[i] - mid) * 2;
	}
	cout << time << " " << mid << "\n";

	return 0;
}

/*
1 8 4
1 2 3 4 5 6 7 8

*/