#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	char ch;
	bool next = false;
	stack<int> a;
	stack<int> b;

	string str;
	cin >> str;
	for (auto e : str)
	{
		a.push(e - '0');
	}
	cin >> str;
	for (auto e : str)
	{
		b.push(e - '0');
	}

	stack<int> sum;
	int nA=0;
	int nB=0;
	bool carry = false;
	while (true)
	{
		if (a.empty() && b.empty())
		{
			if (carry)
				sum.push(carry);
			break;
		}
		if (!a.empty())
		{
			nA = a.top();
			a.pop();
		}
		if (!b.empty())
		{
			nB = b.top();
			b.pop();
		}
		sum.push((nA + nB + carry) % 10);
		if (nA + nB + carry >= 10)
			carry=true;
		else
			carry = false;
		nA = nB = 0;
	}

	while (true)
	{
		if (sum.empty())
			break;
		cout << sum.top();
		sum.pop();
	}

	return 0;
}