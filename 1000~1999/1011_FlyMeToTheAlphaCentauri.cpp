#include <iostream>
using namespace std;

int findCount(int n);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n-- > 0)
	{
		int x, y;
		cin >> x >> y;
		cout<<findCount(y - x)<<"\n";
	}
	
	return 0;
}

int findCount(int n)
{
	int count = 0;
	int speed = 1;
	while (n > 0)
	{
		if (speed * 2 <= n)	// ��߰� ���� �ӵ� ��Ī.
		{
			count += 2;
			n -= speed * 2;
			speed++;
		}
		else if (speed <= n)	// ��Ī���������� �ӵ�+1 �Ҽ�������
		{
			count++;
			n -= speed;
		}
		else
		{
			// �ְ�ӵ� ���ϳ����Ÿ�( �߰��� ���Ӿ��ϰ� �̵��ϸ��, ��: (�Ÿ� 11) 1 2 3 2 2 1 )
			count++;
			n -= n;
		}
	}
	return count;
}