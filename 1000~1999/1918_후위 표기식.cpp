/**
 BOJ 1918
 - 후위 표기식
 - 오후 8:29 2020-11-27
 */


#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<char> oper;
	string str;
	char ch;
	while (cin >> ch)
	{
		if (isalpha(ch))
		{
			cout << ch;
		}
		else
		{
			if (oper.empty())
				oper.push(ch);
			else
			{
				char oTop = oper.top();
				//cout << "oT " << oTop << "\n";
				switch (ch)
				{
				case '+':
				case '-':
					while (true)
					{
						if (oper.empty())
							break;
						oTop = oper.top();
						if (oTop == '*' || oTop == '/' || oTop == '+' || oTop == '-')
						{
							cout << oTop;
							oper.pop();
						}
						else
						{
							break;
						}
					}
					oper.push(ch);
					break;
				case '*':
				case '/':
					oTop = oper.top();
					if (oTop == '*' || oTop == '/')
					{
						cout << oTop;
						oper.pop();
						oper.push(ch);
					}
					else
						oper.push(ch);
					break;
				case '(':
					oper.push(ch);
					break;
				case ')':
					while (true)
					{
						if (oper.empty())
							break;
						//cout <<"rhkf "<< oper.top() << "\n";
						//char t = oper.top();
						if (oper.top() == '(')
						{
							oper.pop();
							break;
						}
						cout << oper.top();
						oper.pop();
					}
					break;
				default:
					break;
				}
			}
		}
	}
	while (true)
	{
		if (oper.empty())
			break;
		if (oper.top() == '(')
		{
			oper.pop();
			continue;
		}
		cout << oper.top();
		oper.pop();
	}

	return 0;
}

/*
A*(B+C)

a+b*c

(a+(b*c))-(d/e)

a+(b*c)-d/e

a*b
(a*b)
a-b
(a-b)
a-b/c
(a-b)/c
(A+B)*C-D
A+B*C+D*E+G
입력: A+B*C+D*E+G
답: ABC*+DE*+G+
오답: ABC*DE*G+++

a*b*c+d
ab*c*d+
*/