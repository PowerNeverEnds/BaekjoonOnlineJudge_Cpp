/*
그리디로 새로 풀어보기
*/
// 뒤로 비교하면서 어떻게든 시간초과 안될려고 이진탐색하면서
// 예외까지 일일이 추가하는 안좋은 알고리즘
#include <iostream>
#include <algorithm>
using namespace std;

int binarySeach(int n, int begin, int end, int** arr);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[2];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	sort(&arr[0], &arr[n], [](int* a, int* b) { return a[1] < b[1]; });
	stable_sort(&arr[0], &arr[n], [](int* a, int* b) { return a[0] < b[0]; });

	int* count = new int[n];
	for (int i = 0; i < n; i++)
	{
		count[i] = 0;
	}
	int max = 0;
	int pMax = n;
	for (int i = n-1; i >= 0; i--)
	{
		int c = 1;
		int iEnd = arr[i][1];
		int p = binarySeach(iEnd, i + 1, n - 1, arr);
		//for (int j = i; j < n; j++)
		//{
		//	if (iEnd <= arr[j][0])
		//	{
		//		if (count[j] != 0)
		//		{
		//c = count[j] + 1;
		if (p <= pMax)
		{
			c = max + 1;
		}
		else if (p < n)
			c = count[p] + 1;
					//break;
				//}
				//c++;
				//iEnd = arr[j][1];
			//}
		//}
		count[i] = c;
		if (max < c)
		{
			max = c;
			pMax = i;
		}
	}
	cout << max << "\n";

	return 0;
}
int binarySeach(int n, int begin, int end, int** arr)
{
	int p = (begin + end) / 2;
	if (end < begin)
	{
		return begin;
	}
	if (arr[p][0] < n)
	{
		return binarySeach(n, p + 1, end, arr);
	}
	else if (arr[p][0] > n)
	{
		return binarySeach(n, begin, p - 1, arr);
	}
	else
	{
		return binarySeach(n, begin, p - 1, arr);
		//return p;
	}
}