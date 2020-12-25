#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, string>> vec;
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		vec.push_back(make_pair(age, name));
	}
	stable_sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a.first < b.first;
		}
	);
	for (auto e = vec.begin(); e < vec.end(); e++)
	{
		cout << e->first <<" "<< e->second << "\n";
	}
	return 0;
}