/**
 *    BOJ 10821
 *    - ������ ����
 *    author:  phcdream
 *    created: ���� 2:48 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	char ch;
	int cnt = 0;
	while (cin >> ch)
	{
		if (ch == ',')
			cnt++;
	}
	cout << cnt + 1 << "\n";

	return 0;
}