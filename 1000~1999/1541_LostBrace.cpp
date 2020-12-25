/*
알고리즘:
1.-가 처음나오는곳까지 나눈후,
2. -앞쪽은 +니까 전부더하기
3.-뒤쪽은 괄호로 묶으면 -니까 전부빼기
예) 
55+50+40-30+20-30+20+20-30
55+50+40    -30+20-30+20+20-30
55+50+40    -(30+20)-(30+20+20)-(30)
앞부분+    뒷부분-
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);
	istringstream input;
	input.str(str);
	string plus;
	getline(input, plus, '-');	// 1. -처음나오는곳 구분

	int begin = 0;
	int end = plus.length();
	int sum = 0;

	// +더하기
	while (plus.find('+', begin) != string::npos)
	{
		end = plus.find('+', begin);
		string tStr = plus.substr(begin, end);
		begin = end + 1;
		int n = stoi(tStr);
		sum += n;	// 더하기
	}
	end = plus.length();
	string tStr = plus.substr(begin, end);	// +쪽 짜투리한개 더하기
	begin = end + 1;
	int n = stoi(tStr);
	sum += n;	// 더하기

	begin = plus.length() + 1;
	end = str.length();
	int pPlus = 0;
	int pMinus = 0;
	while (true)
	{
		pPlus = str.find('+', begin);
		pMinus = str.find('-', begin);
		if ((pPlus == string::npos) && (pMinus == string::npos))
		{
			break;
		}
		int min;
		if (pPlus != string::npos && pMinus != string::npos)
			min = pPlus < pMinus ? pPlus : pMinus;
		else if (pPlus == string::npos)
			min = pMinus;
		else if (pMinus == string::npos)
			min = pPlus;
		end = min;
		string tStr = str.substr(begin, end);
		begin = end + 1;
		int n = stoi(tStr);
		sum -= n;	// 빼기
	}
	end = str.length();
	if (begin < end)
	{
		tStr = str.substr(begin, end);
		begin = end + 1;
		n = stoi(tStr);
		sum -= n;	// 빼기
	}
	cout << sum << "\n";

	return 0;
}

/*
55+50+40-30+20-30
55
55-5
55+5

*/