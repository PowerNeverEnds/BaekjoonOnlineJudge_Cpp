#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n[3];
	for (int i = 0; i < 3; i++)
		cin >> n[i];
	sort(n, n+3);
	cout << n[1] << "\n";

	return 0;
}