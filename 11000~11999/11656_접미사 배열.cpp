#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	cin >> str;
	vector<string> vec;
	for (int i=0;i<str.length();i++)
	{
		vec.push_back(str.substr(i, str.length()));
	}

	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});

	for (auto e : vec)
		cout << e << "\n";

	return 0;
}