/**
 *    BOJ 2467
 *    - 용액
 *    author:  phcdream
 *    created: 오후 4:52 2020-11-30
 */

#include <iostream>

typedef long long ll;

#define INF (2e9+7)

using namespace std;

void in(int& N, int*& arr)
{
	cin >> N;
	arr = new int[(ll)N];
	fill(arr, arr + N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

int myAbs(int a)
{
	return a >= 0 ? a : -a;
}

int* solve(int N, int* arr)
{
	int l, r;
	l = 0;
	r = N - 1;
	int min = INF;
	min = myAbs(arr[l] + arr[r]);
	int* re = new int[2];
	re[0] = arr[l];
	re[1] = arr[r];
	while (true)
	{
		if (l + 1 >= r)
			break;
		int a, b;
		a = myAbs(arr[l + 1] + arr[r]);
		b = myAbs(arr[l] + arr[r - 1]);
		if (a < b)
		{
			l++;
		}
		else
		{
			r--;
		}
		int t = myAbs(arr[l] + arr[r]);
		if (t < min)
		{
			min = t;
			re[0] = arr[l];
			re[1] = arr[r];
		}
	}

	return re;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	in(N, arr);

	int* re = solve(N, arr);
	cout << re[0] << " " << re[1] << "\n";

	return 0;
}