#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	char ch;
	stack<char> operS;
	stack<int> valS;
	int sum = 0;
	while (true)
	{
		cin >> ch;
		if (cin.eof())
			break;
		switch (ch)
		{
		case '(':
		case '[':
			operS.push(ch);
			//valS.push(1);
			break;
		case ')':
			sum = 0;
			if (operS.empty() || operS.top()=='[')
			{
				cout << 0 << "\n";
				return 0;
			}
			else if (operS.top() == '(')
			{
				operS.pop();
				sum = 1;
			}
			else
			{
				while (true)
				{
					if (operS.empty() || operS.top() == '[')
					{
						cout << 0 << "\n";
						return 0;
					}
					if (operS.top() == '(')
					{
						operS.pop();
						break;
					}
					sum += valS.top();
					valS.pop();
					operS.pop();
				}
			}
			operS.push('X');
			valS.push(sum * 2);
			break;
		case ']':
			sum = 0;
			if (operS.empty() || operS.top() == '(')
			{
				cout << 0 << "\n";
				return 0;
			}
			else if (operS.top() == '[')
			{
				operS.pop();
				sum = 1;
			}
			else
			{
				while (true)
				{
					if (operS.empty() || operS.top() == '(')
					{
						cout << 0 << "\n";
						return 0;
					}
					if (operS.top() == '[')
					{
						operS.pop();
						break;
					}
					sum += valS.top();
					valS.pop();
					operS.pop();
				}
			}
			operS.push('X');
			valS.push(sum * 3);
			break;
		default:
			break;
		}
	}
	sum = 0;
	//cout << operS.size() << " " << operS.top() << "\n";
	//cout << valS.size() << " " << valS.top() << "\n";
	while (true)
	{
		if (!operS.empty() && operS.top() != 'X')
		{
			cout << 0 << "\n";
			return 0;
		}
		if (valS.empty())
			break;
		sum += valS.top();
		valS.pop();
		operS.pop();
	}
	//cout << valS.size() << " ";
	cout << sum << "\n";

	return 0;
}

/*
([)]
[(])
[[]]]
[[[]]
[([]])


(()[[]])([])
28

*/