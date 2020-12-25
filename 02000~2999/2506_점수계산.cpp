#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		if (e)
			sum += ++cnt;
		else
			cnt = 0;
	}

	cout << sum << "\n";

	return 0;
}