/*
https://snups.snucse.org/snupc2020/solution.pdf
https://snups.snucse.org/snupc2020/


que  est  ce  que  -il - mange - aujourd'hui.
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

char vo[6] = { 'a','e','i','o','u','h' };
string apo[9] = { "c","j","n","m","t","s","l","d","qu" };

int main()
{
	string str;
	getline(cin, str);
	str += ' ';
	vector<string> vec;
	while (str.find(' ')!=-1 || str.find('-')!=-1)
	{
		//cout << str << "\n";
		if (str.find(' ') != -1 && str.find('-') != -1)
		{
			if (str.find(' ') < str.find('-'))
			{
					if (str.find(' ') == 0)
					{
						str = str.substr(1, str.length());
						continue;
					}
				vec.push_back(str.substr(0, str.find(' ')));
				str = str.substr(str.find(' ') + 1, str.length());
			}
			else if (str.find(' ') > str.find('-'))
			{
					if (str.find('-') == 0)
					{
						str = str.substr(1, str.length());
						continue;
					}
				vec.push_back(str.substr(0, str.find('-')));
				str = str.substr(str.find('-') + 1, str.length());
			}
		}
		else if (str.find(' ') != -1)
		{
			if (str.find(' ') == 0)
			{
				str = str.substr(1,str.length());
				continue;
			}
			vec.push_back(str.substr(0, str.find(' ')  ));
			str = str.substr(str.find(' ')+1, str.length());
		}
		else if (str.find('-') != -1)
		{
			if (str.find('-') == 0)
			{
				str = str.substr(1, str.length());
				continue;
			}
			vec.push_back(str.substr(0, str.find('-') ));
			str = str.substr(str.find('-')+1, str.length());
		}
	}
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		bool isThis = false;
		for (int j = 0; j < 9; j++)
		{
			if (vec[i].find(apo[j] + '\'') == 0)
			{
				for (int k = 0; k < 6; k++)
				{
					if (vec[i][vec[i].find(apo[j] + '\'') + apo[j].length()+1] == vo[k])
					{
						isThis = true;
						break;
					}
				}
				if (isThis == true)
					break;
			}
		}
		if (isThis == true)
		{
			cnt += 2;
		}
		else
		{
			cnt++;
		}
	}
	cout << cnt << "\n";
	//cout << "\n";
	//for (int i = 0; i < vec.size(); i++)
	//	cout << vec[i] << "\n";

	return 0;
}


/*

#include <iostream>
#include <string>
using namespace std;

char vo[6] = { 'a','e','i','o','u','h' };
string apo[9] = { "c","j","n","m","t","s","l","d","qu" };

int main()
{
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' || str[i] == '-')
			str[i] = '/';
	}
	while (true)
	{
		bool isFind = false;
		for (int i = 0; i < 9; i++)
		{
			int sf = str.find(apo[i] + '\'');
			if (sf != -1)
			{
				isFind = true;
				bool isChange = false;
				if ((sf - 1 >= 0 && str[(long long)sf - 1] == '/') || sf == 0)
				{
					for (int j = 0; j < 6; j++)
					{
						if (sf + apo[i].length() + 1 <= str.length() && str[sf + apo[i].length() + 1] == vo[j])
						{
							str[sf + apo[i].length()] = '/';
							isChange = true;
						}
					}
				}
				if (isChange == false)
					isFind = false;
			}
		}
		if (isFind == false)
			break;
	}

	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '/')
			cnt++;
	cout << cnt + 1 << "\n";

	return 0;
}
*/


/*
#include <iostream>
#include <string>
#include <deque>
#include <stack>

using namespace std;

char vo[6] = { 'a','e','i','o','u','h' };
string apo[10] = { "c","j","n","m","t","s","l","l","d","qu" };

int main()
{
	string str;
	getline(cin, str);
	deque<string> dq;
	int prev = 0;
	for(int i=0;i<str.length();i++)
	{
		if (str[i] == ' ' || str[i] == '-')
		{
			dq.push_back(string(str.substr(prev, (long long)i - prev)));
			prev = i + 1;
		}
	}
	dq.push_back(string(str.substr(prev, (long long)str.length() - prev)));

	deque<string> dq2;
	while (!dq.empty())
	{
		string tStr;
		tStr = dq.front();
		dq.pop_front();
		bool isFind = false;
		for (int j = 0; j < 10; j++)
		{
			int p = (int)tStr.find(apo[j] + '\'');
			if (p==0  && (long long)p+1<(long long)tStr.length())
			{
				for (int k = 0; k < 6; k++)
				{
					if (tStr[(long long)p + apo[j].length()+1] == vo[k])
					{
						isFind = true;
						dq2.push_back(tStr.substr(0, apo[j].length() ));
						dq.push_front(tStr.substr(apo[j].length() + 1));
					}
				}
			}
		}
		if (isFind == false)
		{
			if(tStr.size()>0)
				dq2.push_back(tStr);
		}
	}

	cout << dq2.size() << "\n";

	//while (!dq2.empty())
	//{
	//	cout << dq2.front() << "\n";
	//	dq2.pop_front();
	//}


	return 0;
}
*/
/*

j'aime les pommes

qu'est-ce qu'il mange aujourd'hui
qu'est-c'e qu'il mange aujourd'hui

*/