/*
1. 5�� ���������� Ȯ��.
2. �������� 3�߰��� ���� + (n���� 3�߰��ѹ��Ը����� ������ 5) ���.
3. �ȳ������� 3�ϳ� �߰�.
*/
#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int k;
	cin >> n;
	for (int i = 0; i <= n / 3; i++)
	{
		if ((n - i * 3) % 5 == 0)
		{
			k = i + (n - i * 3) / 5;
			cout << k << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}
/*
5 3

1 0 5	1
2 0 10	2

0 1 3	1
0 2 6	2
0 3 9	3
0 4 12	4

1 1 8	2
1 2 11	3
1 3 14	4
2 1 13	3

*/