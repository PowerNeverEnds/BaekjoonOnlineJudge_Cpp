#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N, B;
	cin >> N >> B;
	stack<int> s;
	while (true)
	{
		if (!N)
			break;
		s.push(N % B);
		N /= B;
	}
	while (true)
	{
		if (s.empty())
			break;
		if (s.top() <= 9)
			cout << s.top();
		else
		{
			cout << char(s.top() + 'A' - 10);
		}
		s.pop();
	}

	return 0;
}