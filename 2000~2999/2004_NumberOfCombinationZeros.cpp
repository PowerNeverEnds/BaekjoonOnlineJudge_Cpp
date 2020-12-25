/*
nCm = n!/((n-m)!*m!)


*/

#include <iostream>
using namespace std;

int count(int a, int divisionNum);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	// n!
	int n2, n5;
	n2 = count(n, 2);
	n5 = count(n, 5);

	// (n-m)!
	int nMm2, nMm5;
	nMm2 = count(n-m, 2);
	nMm5 = count(n-m, 5);

	// m!
	int m2, m5;
	m2 = count(m, 2);
	m5 = count(m, 5);
	//cout << n2 << " " << n5 << "\n";
	//cout << nMm2 << " " << nMm5 << "\n";
	//cout << m2 << " " << m5 << "\n";

	// n!/((n-m)!*m!)
	int sum2 = n2 - (nMm2 + m2);
	int sum5 = n5 - (nMm5 + m5);
	//cout << sum2 << " " << sum5 << "\n";
	int min = 0;
	min = sum2 < sum5 ? sum2 : sum5;
	cout << min << "\n";

	return 0;
}

// 
// ��) a=10, divisionNum = 2 ( 10!���� 2�� �����������)
// 1 2 3 4 5 6 7 8 9 10 -> 2�� ��� 10/2=5��(2,4,6,8,10)
// 2 4 6 8 10 -> 4�� ��� 5/2=2�� (4,8) -> 4=2*2 �ϱ� �ѹ��� ������(����2�� �Ʊ��, �ڿ�2�� �̹��� ����)
// 4 8 -> 8�� ��� 2/2=1�� (8) -> 
// 2�� �ѹ��������°� + 2�ει��������°� + 2�� �����������°�
int count(int a, int divisionNum)
{
	int b=0;
	while (a > 0)
	{
		b += a / divisionNum;
		a /= divisionNum;
	}

	return b;
}