/**
 BOJ 10807
 - 개수 세기
 - 오전 2:10 2020-11-29
 */

#include <iostream>

using namespace std;

void init(int& N, int*& arr, int& v)
{
	cin >> N;
	arr = new int[N];
	fill(arr, arr + N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> v;
}

int solve(int& N, int*& arr, int& v)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == v)
			cnt++;
	}

	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	int v;
	init(N, arr,v);

	int re = solve(N, arr,v);
	cout << re << "\n";

	delete[] arr;

	return 0;
}