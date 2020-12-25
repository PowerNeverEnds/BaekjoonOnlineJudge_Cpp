#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int e, s, m;
	cin >>e >> s >> m;
	int sum = 0;
	int key;
	{
		key = e;
		e = (e - (key)) % 15;
		s = (s - (key)) % 28;
		m = (m - (key)) % 19;
		sum += key;
	}
	{
		key = m;
		while (key % 15 != 0)
		{
			key += 19;
		}
		e = (e - (key)) % 15;
		s = (s - (key)) % 28;
		m = (m - (key)) % 19;
		sum += key;
	}
	{
		key = s;
		while (key % 285 != 0)
		{
			key += 28;
		}
		e = (e - (key)) % 15;
		s = (s - (key)) % 28;
		m = (m - (key)) % 19;
		sum += key;
	}
	cout << sum << "\n";
	return 0;
}

/*


4 6 15 34

15*n+4 n=2
28*n+6 n=1
19*n+15 n=1

2 6 5 62
15*n+2 n=4
28*n+6 n=2
19*n+5 n=3

1 16 16 16
15 1 1
28 16 0
19 16 0

15 2 11 4
13 28 9 2
4 19 19 9
15 15 15 4
1 1 1 14

4 6 15 34
5 20 1 14
1 1 1 19

4 6 15 34
1 3 12 3
1 16 16 15
1 1 1 15

// 여기서부터 (작은걸 1로만든다)
// 그다음작은걸 1로만드는데 작은게 1이되는수로한다.
10 18 16 130
1 9 7 9    19%6->25 44 63 82 101 120
1 1 1 120
0 0 0 1

4 6 15 34
1 3 12 3    19%11->30
1 1 1 30
0 0 0 1

*/