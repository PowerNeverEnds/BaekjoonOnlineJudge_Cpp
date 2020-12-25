#include <iostream>
#include <vector>
#include<utility>
using namespace std;

bool exist(string str, vector<pair<string, int>> vec, int& p);
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		cin.ignore();
		string str[30];
		vector<pair<string, int>> vec;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;	// ������ �� (�ǻ��̸�)
			cin >> str;	// �ǻ�����
			int p;	//vector ���� ��ġ
			if (exist(str, vec, p))	// vector�� �ǻ�����str�� �����ϸ�(p ��ġ���� ��), true ��ȯ 
			{
				get<int>(vec[p]) += 1;	// �����ϴ� �ǻ������ϱ� count+1 �ϱ�
			}
			else
				vec.push_back(make_pair(str, 1));	// ������ vector�� push_back( 1�� ó���߰��ϴ� �ǻ������̴ϱ� count =1)
		}

		int sum = 1;
		for (int i = 0; i < vec.size(); i++)
		{
			sum *= (get<int>(vec[i]) + 1);	// �ǻ����� �Ȱ��°� +1
		}
		cout << sum - 1 << "\n";	// �˸� 1������(��� �Ȱ���)
	}
	return 0;
}
// vector���� str�� �����ϸ� p�� ��ġ���� �� true ��ȯ
bool exist(string str, vector<pair<string, int>> vec, int& p)
{
	int j;
	for (j = 0; j < vec.size(); j++)
	{
		if (str == get<string>(vec[j]))
		{
			p = j;
			return true;
		}
	}
	return false;
}