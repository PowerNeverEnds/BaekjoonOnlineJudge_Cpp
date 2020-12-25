#include <iostream>
using namespace std;

bool hanSoo(int& n, int m, int& div);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int count=0;
	for (int i = 1; i <= n; i++)
	{
		int m=0;
		int n = i;
		int div;
		if (hanSoo(n, m, div))
		{
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}

// n�� ����, div�� �� �� �μ� ����
// 3589 -> 358,9 -> 35,8 -> 3,5 ������ ����Լ� ȣ��Ǿ� �Ǿ� ���ں��� ��
// div = -2 ���ǰ�, return true;
// ���� ����Լ� return �ϸ鼭, n-m�� div �� ���ϸ鼭, �ٸ��� ���Ŀ� ��� false ����. 
bool hanSoo(int& n, int m, int& div)
{
	if (n < 10)
	{
		div = n - m;
		return true;
	}
	else
	{
		m = n % 10;
		n /= 10;
		if (hanSoo(n, m, div) && n - m == div )	// �������� true �̸鼭, �̹��ڸ����� n - m == div�϶�.
		{
			n = m;
			return true;
		}
		else
		{
			n = m;
			return false;
		}
	}
}