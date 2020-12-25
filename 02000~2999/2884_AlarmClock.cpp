#include <iostream>
using namespace std;

int main()
{
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int h, m;
	cin >> h >> m;

	if (m < 45)
		h = (h+23) % 24;
	m = (m+15) % 60;

	cout << h << " " << m << "\n";
}