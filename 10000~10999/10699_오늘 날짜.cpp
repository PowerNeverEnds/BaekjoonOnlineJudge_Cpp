/**
 *    BOJ 10699
 *    - 오늘 날짜
 *    author:  phcdream
 *    created: 오전 1:57 2020-12-06
**/

#include <iostream>
#include <ctime>
#include <iomanip>
//#include <time.h>

using namespace std;

int main()
{
	time_t curTime = time(nullptr);
	time_t t = time(NULL);
	struct tm buf;
	char str[26];
	//asctime_s(str, sizeof str, gmtime_s(&t, &buf));
	cout << curTime << "\n";
	//cout <<  << "\n";
	//cout < asctime(&buf) << "\n";
	struct tm start;// = { .tm_mday = 1 };
	mktime(&start);
	printf("%s\n", asctime(&start));
	return 0;
}
