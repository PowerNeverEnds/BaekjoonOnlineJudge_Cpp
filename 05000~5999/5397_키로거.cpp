#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin.ignore();
		cin >> str;
		deque<char> dqL;
		deque<char> dqR;
		for (auto e : str)
		{
			if (e == '<')
			{
				if (!dqL.empty())
				{
					dqR.push_front(dqL.back());
					dqL.pop_back();
				}
			}
			else if (e == '>')
			{
				if (!dqR.empty())
				{
					dqL.push_back(dqR.front());
					dqR.pop_front();
				}
			}
			else if (e == '-')
			{
				if (!dqL.empty())
				{
					dqL.pop_back();
				}
			}
			else
			{
				dqL.push_back(e);
			}
		}

		for (auto e : dqL)
			cout << e;
		for (auto e : dqR)
			cout << e;
		cout << "\n";
	}

	return 0;
}