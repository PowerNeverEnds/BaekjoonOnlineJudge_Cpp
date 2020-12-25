#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool arr[10001] = { 0, };
	for (int i = 1; i <= 10000; i++)
	{
		int sum = i;
		int number = i;
		while (number != 0)
		{
			sum+=number % 10;
			number /= 10;
		}
		if (sum <= 10000)
			arr[sum] = true;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == false)
			cout << i << "\n";
	}
	return 0;
}