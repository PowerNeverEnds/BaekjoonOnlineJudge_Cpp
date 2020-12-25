/**
 *    BOJ 2473
 *    - 세 용액
 *    author:  phcdream
 *    created: 오후 3:52 2020-12-01
 */

#include <iostream>
#include <algorithm>

typedef long long ll;

#define INF (ll(1e10+7))
using namespace std;

template <typename T>
T myAbs(T a)
{
	return a >= 0 ? a : -a;
}

void in(int& N, ll*& arr)
{
	cin >> N;
	arr = new ll[(ll)N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

int myBinSearch(int i, int j, int N, ll* arr)
{
	int l = j + 1;
	int r = N - 1;
	ll sij = arr[i] + arr[j];
	ll min = INF;
	int p = -1;
	while (true)
	{
		if (l > r)
			break;
		int m = (l + r) / 2;
		//cout << arr[i] << " " << arr[j] << " " << arr[m]<<"  "<<l<<" "<<m<<" "<<r << "\n";
		ll e = sij + arr[m];
		ll absE = myAbs(e);
		//cout << absE << " " << min << "\n";
		if (absE < min)
		{
			min = absE;
			p = m;
			//cout << absE << " " << min << "\n";
		}
		if (e == 0)
		{
			break;
		}
		else if (e < 0)
		{
			l = m + 1;
		}
		else if (e > 0)
		{
			r = m - 1;
		}
	}

	return p;
}

int* solve(int N, ll* arr)
{
	sort(arr, arr + N, [](auto a, auto b) {
		return a < b;
		});

	//for (int i = 0; i < N; i++)
	//	cout << arr[i] << " ";
	//cout << "\n";
	ll min = INF;
	int* sel = new int[3];
	fill(sel, sel + 3, 0);// [3] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int k = myBinSearch(i, j, N, arr);
			if (k == -1)
				continue;
			ll sum = arr[i] + arr[j] + arr[k];
			ll absSum = myAbs(sum);
			if (absSum < min)
			{
				sel[0] = i;
				sel[1] = j;
				sel[2] = k;
				min = absSum;
			}
		}
	}

	//for (int i = 0; i < 3; i++)
	//	cout << sel[i] << " ";
	//cout << "\n";
	return sel;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	ll* arr;
	in(N, arr);

	int* re = solve(N, arr);
	//cout << re[0] << " " << re[1] << " " << re[2] << "\n";
	for (int i = 0; i < 3; i++)
		cout << arr[re[i]] << " ";
	cout << "\n";

	return 0;
}
/*
5
-2 6 -97 -6 98
-97 -2 98

3
1 2 3
*/

/*
5
999999999
1000000000
1000000000
1000000000
1000000000

5
-999999999
-1000000000
-1000000000
-1000000000
-1000000000
*/