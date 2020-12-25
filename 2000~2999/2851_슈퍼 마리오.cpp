/**
 *    BOJ 2851
 *    - ���� ������
 *    author:  phcdream
 *    created: ���� 7:01 2020-12-05
**/

#include <iostream>

using namespace std;

int myAbs(int a)
{
	return a >= 0 ? a : -a;
}

int main()
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int e;
		cin >> e;
		if (myAbs(sum - 100) >= myAbs(sum + e - 100))
		{
			sum += e;
		}
		else
			break;
	}
	cout << sum << "\n";

	return 0;
}