
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	list<char> l;
	for (auto e : str)
		l.push_back(e);
	list<char>::iterator iter = l.end();// = --l.end();
	//iter--;
	//cout << *iter << "\n";

	int M;
	cin >> M;
	while (M--)
	{
		//if(iter!=l.end())
		//	cout << *iter << "\n";
		char oper;
		cin >> oper;
		switch (oper)
		{
		case 'L':
			if (iter == l.begin())// || l.empty())
			{
			}
			else
			{
				iter--;
			}
			break;
		case 'D':
			if (iter == l.end())// || l.empty())
			{
			}
			else
			{
				iter++;
			}
			break;
		case 'B':
			if (iter == l.begin())// || l.empty())
			{
			}
			else
			{
				//list<char>::iterator tIter = iter;
				//l.erase(--tIter);
				iter = l.erase(--iter);
			}
			break;
		case 'P':
			char tCh;
			cin >> tCh;
			l.insert(iter, tCh);
			break;
		default:
			break;
		}
	}

	for (auto e : l)
		cout << e;
	cout << "\n";

	return 0;
}