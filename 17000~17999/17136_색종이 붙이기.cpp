/**
 *    BOJ 17136
 *    - 색종이 붙이기
 *    author:  phcdream
 *    created: 오전 5:09 2020-12-06
**/

#include <iostream>

typedef long long ll;

#define N 10

using namespace std;

void in(int**& arr)
{
	arr = new int* [(ll)N];
	fill(arr, arr + N, nullptr);
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[(ll)N];
		fill(arr[i], arr[i] + N, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void solve(int** arr)
{

}
int main()
{
	int** arr;
	in(arr);

	solve(arr);

	return 0;
}