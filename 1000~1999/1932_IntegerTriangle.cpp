/*
1932_IntegerTriangle
�˰���:
1. t�� n�� �Է¹޴´�,
2. �迭�� i�� i-1 ���� ū���� �����ؼ� n�� ���ؼ� i�� �ִ´�.
��)
�Է� -> ����	�迭��ȣ
�Է�			0 1 2 3 4
=========
7
3 8			10 15
8 1 0		18 16 15	// ���⼭ 16�� ���� 1+15�� 12 �� 15�� ū���� �����ؼ� 1������
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