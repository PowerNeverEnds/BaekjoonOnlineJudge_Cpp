/**
 *    BOJ 5522
 *    - ī�� ����
 *    author:  phcdream
 *    created: ���� 2:19 2020-12-01
 */

#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int e;
		cin >> e;
		sum += e;
	}
	
	cout << sum << "\n";

	return 0;
}