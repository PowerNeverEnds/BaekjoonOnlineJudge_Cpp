#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	int i = 0;
	for (i = 0;; i++)
	{
		cin >> str;
		if (cin.eof())
		{
			break;
		}
	}
	cout << i << "\n";

	return 0;
}
/*
https://www.acmicpc.net/board/view/59985
*/

//#include <iostream>
////#define _REGEX_MAX_STACK_COUNT 2000000
//#include <regex>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//#define DIV 100000
//
//int wordCount(string& str) {
//
//	string& s = str;
//
//	std::regex words_regex("[^\\s]+");
//	int len = str.length();
//	int cnt = 0;
//	for (int i = 0; i * DIV < len; i++)
//	{
//		std::sregex_iterator words_begin;
//		if ((i + 1) * DIV < len)
//		{
//			words_begin =
//				std::sregex_iterator(s.begin() + i * DIV, s.begin() + (i + 1) * DIV, words_regex);
//		}
//		else
//		{
//			words_begin =
//				std::sregex_iterator(s.begin() + i * DIV, s.end(), words_regex);
//		}
//		auto words_end = std::sregex_iterator();
//		cnt += distance(words_begin, words_end);
//		if (i != 0)
//		{
//			if (s[(i)* DIV - 1] != ' ' && s[(i)* DIV] != ' ')
//			{
//				cnt--;
//			}
//		}
//		//cout << distance(words_begin, words_end) << "\n";
//	}
//
//	return cnt;
//}
//
//void solve() {
//	//ifstream cin;
//	//cin.open("input.txt");
//	string str;
//	getline(cin, str);
//	cout << wordCount(str) << '\n';
//	//cin.close();
//}
//
//int main() {
//	solve();
//	//int n;
//	//cin >> n;
//	return 0;
//}