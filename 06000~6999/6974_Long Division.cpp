/**
 *    BOJ 6974
 *    - Long Division
 *    author:  phcdream
 *    created: ¿ÀÈÄ 9:17 2020-12-11
**/

#include <iostream>
#include <string>

using namespace std;

struct MyInt
{
	string str;
	
	MyInt operator/(const MyInt& mi)const {
		int size = str.length() - mi.str.length();
		int p = size;
		MyInt tMi{ str };
		while (true)
		{
			//tMi.str
		}
		return *this;
	}
};

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tStr;
		MyInt mi1, mi2;
		cin.ignore();
		cin >> mi1.str;
		cin.ignore();
		cin >> mi2.str;
		MyInt re = mi1 / mi2;
		cout << re.str << "\n";
		
	}
	return 0;
}