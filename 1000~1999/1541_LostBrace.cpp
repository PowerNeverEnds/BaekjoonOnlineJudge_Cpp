/*
�˰���:
1.-�� ó�������°����� ������,
2. -������ +�ϱ� ���δ��ϱ�
3.-������ ��ȣ�� ������ -�ϱ� ���λ���
��) 
55+50+40-30+20-30+20+20-30
55+50+40    -30+20-30+20+20-30
55+50+40    -(30+20)-(30+20+20)-(30)
�պκ�+    �޺κ�-
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);
	istringstream input;
	input.str(str);
	string plus;
	getline(input, plus, '-');	// 1. -ó�������°� ����

	int begin = 0;
	int end = plus.length();
	int sum = 0;

	// +���ϱ�
	while (plus.find('+', begin) != string::npos)
	{
		end = plus.find('+', begin);
		string tStr = plus.substr(begin, end);
		begin = end + 1;
		int n = stoi(tStr);
		sum += n;	// ���ϱ�
	}
	end = plus.length();
	string tStr = plus.substr(begin, end);	// +�� ¥�����Ѱ� ���ϱ�
	begin = end + 1;
	int n = stoi(tStr);
	sum += n;	// ���ϱ�

	begin = plus.length() + 1;
	end = str.length();
	int pPlus = 0;
	int pMinus = 0;
	while (true)
	{
		pPlus = str.find('+', begin);
		pMinus = str.find('-', begin);
		if ((pPlus == string::npos) && (pMinus == string::npos))
		{
			break;
		}
		int min;
		if (pPlus != string::npos && pMinus != string::npos)
			min = pPlus < pMinus ? pPlus : pMinus;
		else if (pPlus == string::npos)
			min = pMinus;
		else if (pMinus == string::npos)
			min = pPlus;
		end = min;
		string tStr = str.substr(begin, end);
		begin = end + 1;
		int n = stoi(tStr);
		sum -= n;	// ����
	}
	end = str.length();
	if (begin < end)
	{
		tStr = str.substr(begin, end);
		begin = end + 1;
		n = stoi(tStr);
		sum -= n;	// ����
	}
	cout << sum << "\n";

	return 0;
}

/*
55+50+40-30+20-30
55
55-5
55+5

*/