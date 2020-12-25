/**
 *    BOJ 2935
 *    - 소음
 *    author:  phcdream
 *    created: 오전 1:22 2020-12-05
**/

#include <iostream>
#include <string>

using namespace std;

int myMax(int a, int b)
{
	return a >= b ? a : b;
}

void strAppend(string& A, string& B)
{

	string t;
	t.append(B.length() - A.length(), '0');
	//cout << t << "\n";
	A = t.append(A);
}

int main()
{
	string A;
	cin >> A;
	char oper;
	cin >> oper;
	string B;
	cin >> B;

	//cout << A << oper << B << "\n";

	switch (oper)
	{
	case '+':
	{
		string str;
		int len = myMax(A.length(), B.length());
		if (A.length() < B.length())
		{
			strAppend(A,B);
		}
		else
		{

			strAppend(B, A);
		}
		//cout << len << "\n";
		//cout << A << "\n" << B << "\n";
		for (int i = 0; i < len; i++)
		{
			if (A[i] == '1' && B[i]=='1')
			{
				cout << 2;

			}
			else if(A[i]=='1' || B[i]=='1')
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		break;
	}
	case '*':
	{
		cout << 1;
		int len = (A.length() - 1) + (B.length() - 1);
		for (int i = 0; i < len; i++)
		{
			cout << '0';
		}
		break;
	}
	default:
		break;
	}
	return 0;
}
/*

1000
*
100

1000
+
100

.
*/