#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	bool* prime = new bool[10001];	// �� n��°�� �Ҽ��̸� true
	for (int i = 0; i <= 10000; i++)
	{
		prime[i] = true;
	}
	prime[1] = false;
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i] == true)
		{
			for (int j = 2; i * j <= 10000; j++)
			{
				prime[i * j] = false;
			}
		}
	}
	while (n-- > 0)
	{
		int number;
		cin >> number;
		for (int i = number / 2; i > 0; i--)	// ���̰� �����ͺ��� ���ϱ����ؼ� �߰����� i--
		{
			if (prime[i] == true && prime[number - i] == true)	// i + X = number ���� X�� �Ҽ�����
			{
				cout << i << " " << number - i << "\n";
				break;
			}
		}
	}

	return 0;
}
