#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	char ch;
	while (true)
	{
		cin >> ch;
		if (cin.eof())
			break;
		s.push(ch - '0');
	}
	stack<int> out;
	while (true)
	{
		if (s.empty())
			break;
		int n = 0;
		int k = 1;
		for (int i = 0; i < 3; i++)
		{
			if (s.empty())
				break;
			n = n + s.top() * k;
			k *= 2;
			s.pop();
		}
		out.push(n);
	}

	while (true)
	{
		if (out.empty())
			break;
		cout << out.top();
		out.pop();
	}

	return 0;
}