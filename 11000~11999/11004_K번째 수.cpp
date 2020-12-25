#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	//sort(arr, arr + N, [](auto a, auto b) {
	//	return a < b;
	//	});

	nth_element(arr,arr+K-1,arr+N, [](auto a, auto b) {
			return a < b;
			});


	cout << arr[K - 1] << "\n";

	return 0;
}