/**
 *    BOJ 2789
 *    - 유학 금지
 *    author:  phcdream
 *    created: 오전 2:46 2020-12-03
**/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	string CAMBRIDGE="CAMBRIDGE";
	string nStr = "";
	for (auto e : str)
	{
		bool isSame = false;
		for (auto E : CAMBRIDGE)
		{
			if (e == E)
			{
				isSame = true;
				break;
			}
		}
		if (isSame == false)
			nStr.push_back(e);
	}

	cout << nStr << "\n";

	return 0;
}