#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	bool arr[50][50] = { 0, };
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = str[j]=='W'?true:false;
		}
	}
	int sameMaxValue = 0;
	for (int i = 0; i <= n-8; i++)
	{
		for (int j = 0; j <= m-8; j++)
		{
			int count = 0;	// ���� ���� ����(��) ī��Ʈ
			for (int y = i; y < i + 8; y++)
			{
				for (int x = j; x < j + 8; x++)
				{
					//	x+y���� ¦Ȧ�� ����ó���̷���
					// 0123
					// 1234
					// 2345
					if (arr[y][x] == (x + y) % 2)
					{
						count++;
					}
				}
			}
			count = abs(count - 32);	// count�� 32���� �ּ���, 0�̳� 64�� �������� �´� ������ ����.
			count += 32;	// �ִ밪 64�� �ҷ���
			sameMaxValue = count > sameMaxValue ? count : sameMaxValue;
		}
	}
	cout << 64 - sameMaxValue << "\n";
	return 0;
}