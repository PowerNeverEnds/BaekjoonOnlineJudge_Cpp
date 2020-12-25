#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin>>arr[i];

	int max = 0;
	for (int i = 0; i < N; i++)
		max = arr[i] > max ? arr[i] : max;

	int M;
	cin >> M;

	int l = 0, r = max;
	int mid;
	int sum;
	while (true)
	{
		if (l > r)
			break;
		sum = 0;
		mid = (l + r) / 2;
		for (int i = 0; i < N; i++)
			if (arr[i] < mid)
				sum += arr[i];
			else
				sum += mid;
		if (sum < M)
			l = mid + 1;
		else if (sum > M)
			r = mid - 1;
		else if (sum == M)
			break;
	}
	if (sum == M)
		cout << mid << "\n";
	else
		cout << l - 1 << "\n";

	return 0;
}