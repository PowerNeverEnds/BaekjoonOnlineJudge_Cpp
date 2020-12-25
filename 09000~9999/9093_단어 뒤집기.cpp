/**
 BOJ 9093
 - 단어 뒤집기
 - 오전 2:32 2020-11-29
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

void init(string& str)
{
	getline(cin, str);
}

template <typename T>
void mySwap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T>
void myIterSwap(T a, T b)
{
	mySwap(*a, *b);

}

template <typename T>
void myReverse(T l, T r)
{
	while (l != r && l != --r) {
		myIterSwap(l++, r);
	}
}

string solve(string str)
{
	string tStr = str;
	string::iterator l = tStr.begin();
	string::iterator r;

	for (string::iterator i = tStr.begin(); i != tStr.end(); i++)
	{
		r = i;
		if (isspace(*i))
		{
			myReverse(l, r);
			l = i + 1;
		}
	}

	r = tStr.end();
	myReverse(l, r);

	return tStr;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		string str;
		init(str);

		string reStr = solve(str);

		cout << reStr << "\n";
	}

	return 0;
}