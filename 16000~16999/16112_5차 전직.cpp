#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		vec.push_back(e);
	}
	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});
	ull sum = 0;
	ull count = 0;
	for (auto e : vec)
	{
		sum += count * e;
		if (count < k)
			count++;
	}
	cout << sum << "\n";

	return 0;
}