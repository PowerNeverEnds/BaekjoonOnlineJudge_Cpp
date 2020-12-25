#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	const bool POP_FRONT = true;
	const bool POP_BACK = false;
	int t;
	cin >> t;
	while (t-- > 0)
	{
		string p;
		cin >> p;
		int n;
		cin >> n;
		cin.ignore(1, '\n');
		string str;
		string t;
		deque<int> dQ;
		getline(cin, t, '[');
		int i = 0;
		for (i = 0; i < n - 1; i++)
		{
			getline(cin, str, ',');
			dQ.push_back(stoi(str));
		}
		getline(cin, str,']');
		if(str!="")dQ.push_back(stoi(str));
		bool pop=POP_FRONT;
		bool error = false;
		for(int i=0;i<p.length();i++)
		{
			if (p[i] == 'R')
			{
				pop = (pop==POP_FRONT)?POP_BACK:POP_FRONT;
			}
			else if (p[i] == 'D')
			{
				if (dQ.empty())
				{
					error = true;
					break;
				}
				else if (pop == POP_FRONT)
				{
					dQ.pop_front();
				}
				else if(pop == POP_BACK)
				{
					dQ.pop_back();
				}
			}
		}
		if (error == true)
			cout << "error" << "\n";
		else
		{
			cout << "[";
			if (!dQ.empty())
			{
				if (pop == POP_FRONT)
				{
					for (int i = 0; i < dQ.size() - 1; i++)
					{
						cout << dQ[i] << ",";
					}
					cout << dQ[dQ.size() - 1];
				}
				if (pop == POP_BACK)
				{
					for (int i = dQ.size() - 1; i >0; i--)
					{
						cout << dQ[i] << ",";
					}
					cout << dQ[0];
				}
			} 
			cout<<"]" << "\n";
		}
	}
	return 0;
}