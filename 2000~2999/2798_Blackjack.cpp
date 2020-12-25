#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int arr[100] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int count = 0, close = 0;	// ���� M�� ���� �ʴ� ī�� 3���� ã�� �� �ִ� ��츸 �Է����� �־�����.(close = 0 �� ����)
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
			{
				int t = arr[i] + arr[j] + arr[k];
				if ((t < m) && ((m - t) < (m - close)))
					close = t;
				if (t == m)
				{
					cout << m << "\n";	// close == t == m
					return 0;
				}
			}
	cout << close << "\n";
	
	return 0;
}