/*
https://www.acmicpc.net/board/view/8889

https://www.acmicpc.net/board/view/34565

*/

#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
	string strA;
	cin >> strA;
	//getline(cin, strA);
	string strB;
	cin.ignore();
	cin >> strB;
	//getline(cin, strB);

	string tStr = "";
	int p = 0;
	for (int i = 0; i < strA.length(); i++)
	{
		tStr += strA[i];
		p = tStr.length()-strB.length();
		//cout << tStr << " " << p << "\n";
		if (p < 0)
			p = 0;
		int f = tStr.find(strB, p);
		if (f == -1)
			continue;
		else if (f != -1)
		{
			for (int i = 0; i < strB.length(); i++)
				tStr.pop_back();
			//p -= strB.length();
			//if (p < 0)
			//	p = 0;
		}
	}
	if (tStr.length() == 0)
		cout << "FRULA" << "\n";
	else
		cout << tStr << "\n";


	return 0;
}