/*
1932_IntegerTriangle
알고리즘:
1. t번 n을 입력받는다,
2. 배열의 i와 i-1 값중 큰값을 선택해서 n과 더해서 i에 넣는다.
예)
입력 -> 저장	배열번호
입력			0 1 2 3 4
=========
7
3 8			10 15
8 1 0		18 16 15	// 여기서 16을 보면 1+15로 12 와 15중 큰수를 선택해서 1과더함
2 7 4 4
4 5 2 6 5
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int arr[501] = { 0, };
	int tArr[501] = { 0, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int number;
			cin >> number;
			if (j == 0)
				tArr[0] += number;
			else
			{
				tArr[j] = number + (arr[j - 1] > arr[j] ? arr[j - 1] : arr[j]);
			}
		}
		for (int j = 0; j <= i; j++)
		{
			arr[j] = tArr[j];
		}

	}

	sort(&arr[0], &arr[n]);

	cout << arr[(n - 1) >= 0 ? (n - 1) : 0] << "\n";

	return 0;
}