/**
 *    BOJ 1783
 *    - ���� ����Ʈ
 *    author:  phcdream
 *    created: ���� 7:45 2020-12-07
**/

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	if (N == 1 || M == 1 || (M == 2 && N == 2))
	{
		cout << 1 << "\n";
	}
	else if (N == 2)
	{
		if (M < 1 + 2 * 4)	// ��ġ����
		{
			cout << 1 + (M - 1) / 2 << "\n";
		}
		else
		{
			cout << 1 + 3 << "\n";	// ��ġ����
		}
	}
	else if (M <= 4)
	{
		cout << 1 + (M - 1) << "\n";
	}
	else if (M <= 6)
	{
		cout << 1 + 3 << "\n";
	}
	else
	{
		int cnt = 1;
		int m = M - 1;

		cnt += 4;
		m = m - 6;
		cout << cnt + m << "\n";
	}

	return 0;
}

/*
2 9
*/