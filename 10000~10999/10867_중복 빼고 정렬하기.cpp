#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		vec.push_back(e);
	}

	sort(vec.begin(), vec.end(), [](auto a, auto b) {
		return a < b;
		});

	int prev = vec.front();
	cout << vec.front() << " ";
	for (auto e : vec)
	{
		if (e == prev)
		{
			continue;
		}
		else
		{
			cout << e << " ";
			prev = e;
		}
	}

	return 0;
}