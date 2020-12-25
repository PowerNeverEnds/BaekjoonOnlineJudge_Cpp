/**
 *    BOJ 5988
 *    - 홀수일까 짝수일까
 *    author:  phcdream
 *    created: 오전 7:22 2020-12-05
**/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin.ignore();
		cin >> str;
		switch (str.back())
		{
		case'0':
		case '2':
		case '4':
		case '6':
		case '8':
			cout << "even" << "\n";
			break;
		case '1':
		case '3':
		case '5':
		case '7':
		case '9':
			cout << "odd" << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}