#include <iostream>
#include <string>

#define R 31
#define M 1234567891

typedef unsigned long long ull;

using namespace std;

int main()
{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);

	int L;
	string str;
	cin >> L;
	cin.ignore();
	ull H = 0;
	ull r = 1;
	for (int i = 0; i < L; i++)
	{
		int a;
		a = getchar();
		a = a - 'a' + 1;
		H = (H + (a * r) % M) % M;
		r = (r * R) % M;
	}
	cout << H << "\n";

	return 0;
}