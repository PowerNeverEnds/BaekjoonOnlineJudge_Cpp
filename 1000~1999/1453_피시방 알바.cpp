/**
 *    BOJ 1453
 *    - �ǽù� �˹�
 *    author:  phcdream
 *    created: ���� 6:22 2020-12-06
**/

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int N;
	cin >> N;
	set<int> s;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int e;
		cin >> e;
		if (s.count(e))
			cnt++;
		s.insert(e);
	}
	cout << cnt << "\n";

	return 0;
}