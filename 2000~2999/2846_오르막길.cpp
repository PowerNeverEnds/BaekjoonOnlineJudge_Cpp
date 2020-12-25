/**
 *    BOJ 2846
 *    - 오르막길
 *    author:  phcdream
 *    created: 오전 5:58 2020-12-05
**/

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	int l = 0;
	int prev = -1;
	int on = false;
	int max = 0;
	cin >> prev;
	for (int i = 1; i < N; i++)
	{
		int e;
		cin >> e;
		if (prev < e)
		{
			if (on == false)
			{
				l = prev;
				on = true;
			}
			max = (e - l) > max ?(e - l) : max;
			//cout << e << " " << l << " " << max << "\n";

		}
		else
		{
			on = false;
		}
		prev = e;
	}

	cout << max << "\n";

	return 0;
}
/*

8
12 20 1 3 4 4 11 1
4

1
0

1
2

2
0 1

2
1 0

6

3  2  2  1  10  1
*/