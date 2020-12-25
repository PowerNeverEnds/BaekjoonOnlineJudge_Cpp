#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	int max = 0;
	for (int i = 0; i < B.length(); i++)
	{
		int cnt = 0;
		if (i + A.length() > B.length())
			break;
		for (int j = 0; j < A.length(); j++)
		{
			if (B[(ll)i+j] == A[j])
				cnt++;
		}
		max = cnt > max ? cnt : max;
	}

	cout << A.length()-max << "\n";

	return 0;
}

/*
aa
baab
0

ab
bbaa
1

cabc
bbbbaaa
3

cabc
aaaabbbb
2

*/