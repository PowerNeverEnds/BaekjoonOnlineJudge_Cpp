/**
 *    BOJ 2592
 *    - ��ǥ��
 *    author:  phcdream
 *    created: ���� 2:22 2020-12-01
 */

#include <iostream>

using namespace std;

int main()
{
	int a[101] = { 0, };
	int max = 0;
	int maxInd = 0;
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int e;
		cin >> e;
		sum += e;
		int ind = e / 10;
		a[ind]++;
		if (a[ind] > max)
		{
			max = a[ind];
			maxInd = ind;
		}
	}

	cout << sum / 10 << "\n";
	cout << maxInd * 10 << "\n";

	return 0;
}