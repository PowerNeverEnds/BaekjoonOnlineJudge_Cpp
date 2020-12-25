#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		int t;
		cin >> t;
		if (n == t)
			cnt++;
	}

	cout << cnt << "\n";
	
	return 0;
}