#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool remainder[42] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		int number;
		cin >> number;
		remainder[number % 42] = true;
	}
	int count=0;
	for (int i = 0; i < 42; i++)
	{
		count += remainder[i];
	}
	cout << count << "\n";

	return 0;
}