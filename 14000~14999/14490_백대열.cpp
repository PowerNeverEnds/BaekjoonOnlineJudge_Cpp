#include <iostream>
#include <string>

using namespace std;

int gcd(int n, int m)
{
	while (m != 0)
	{
		int t = m;
		m = n % m;
		n = t;
	}
	return n;
}

int main()
{
	int n, m;
	string str;
	cin >> str;
	n = stoi(str.substr(0, str.find(':')));
	m = stoi(str.substr(str.find(':') + 1, str.length()));

	int g = gcd(n, m);
	cout << n / g << ":" << m / g << "\n";

	return 0;
}