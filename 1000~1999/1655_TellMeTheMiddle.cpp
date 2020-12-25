/*
�˰���:
1.�Է¹޴´�� ������ ���� ū�����ݵǰ� (min, max) priority_queue�� ����
2.�� ���
*/
#include <iostream>
#include <queue>
using namespace std;

void swap(int& a, int& b);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	priority_queue<int,vector<int>> maxPQ;	// ������������, (top��ū��(�������� ��� ���־���ϱ⶧��))
	priority_queue<int,vector<int>,greater<int>> minPQ;	// ������ū��, top��������
	{
		if (n == 1)
		{
			int a;
			cin >> a;
			cout << a << "\n";
			n--;	// �̰� �߰�( ���ϸ� �ڿ� while������)
		}
		else if (n > 1)
		{
			int a, b;
			cin >> a >> b;
			cout << a << "\n";	// �ȱ�鼭 �׳� a ���
			if (a < b)
			{
				swap(a, b);
			}
			maxPQ.push(b);
			minPQ.push(a);
			cout << maxPQ.top() << "\n";	// �����ִ� Cout ���� �ȱ�
			n -= 2;
		}
	}
	while (n-- > 0)
	{
		int number;
		cin >> number;
		if (maxPQ.top() >= number)
		{
			if (maxPQ.size() > minPQ.size())
			{
				minPQ.push(maxPQ.top());
				maxPQ.pop();
			}
			maxPQ.push(number);
		}
		else if (minPQ.top()<=number)	// ���� ����
		{
			if (maxPQ.size() < minPQ.size())
			{
				maxPQ.push(minPQ.top());
				minPQ.pop();
			}
			minPQ.push(number);
		}
		else if (maxPQ.top() < number && minPQ.top() > number)	// ����� �߰�
		{

			if (maxPQ.size() <= minPQ.size())
			{
				maxPQ.push(number);
			}
			else if (maxPQ.size() > minPQ.size())
			{
				minPQ.push(number);
			}
		}
		if (maxPQ.size() >= minPQ.size())
		{
			cout << maxPQ.top() << "\n";
		}
		else if (maxPQ.size() < minPQ.size())
		{
			cout << minPQ.top() << "\n";
		}
	}

	return 0;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}