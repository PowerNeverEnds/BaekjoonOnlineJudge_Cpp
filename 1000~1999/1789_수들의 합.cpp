#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	ll S;
	cin >> S;
	ll sum = 0;
	int i = 0;
	for (i = 0; i <= S; i++)
	{
		sum += i;
		//cout << sum <<" "<< i << "\n";
		if (S < sum)
			break;
	}
	cout << i - 1 << "\n";

	return 0;
}