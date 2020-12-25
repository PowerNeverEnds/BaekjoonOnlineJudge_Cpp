#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double distance, disX, disY;
		disX = x1 - x2;
		disY = y1 - y2;
		distance = sqrt(pow(disX, 2) + pow(disY, 2));
		
		// ����
		if (distance == (r1 + r2))
		{
			cout << 1 << "\n";
		}
		// ����
		else if (distance == 0 && r1 == r2)
		{
			cout << -1 << "\n";
		}
		// ����
		else if (distance == abs(r1-r2))
		{
			cout << 1 << "\n";
		}
		// ����(�������� ū���ȿ� �� ���)
		else if (distance < abs(r1 - r2))
		{
			cout << 0 << "\n";
		}
		// ���Ե����� �����鼭 �������� ���� ���
		else if (distance > (r1 + r2))
		{
			cout << 0 << "\n";
		}
		// �������� ������ ���
		else
		{
			cout << 2 << "\n";
		}
	}

	return 0;
}