/**
 *    BOJ 1300
 *    - K번째 수
 *    author:  phcdream
 *    created: 오전 1:04 2020-12-03
**/

#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	int K;
	cin >> K;
	int i;
	//int* mem = new int[N * N + 1];
	//fill(mem, mem + N * N + 1, 0);
	for (i = 1; i <= N * N; i++)
	{
		//int n = i;
		int tCnt = 0;
		for (int j = 1; j*j <= N && j<=i; j++)
		{
			if (i / j > N)
				continue;
			if (i % j == 0)
			{
				cnt++;
				tCnt++;
			}
			if (cnt >= K)
				break;
		}
		cnt += tCnt;
		if (i == N*N)
		{
			//cnt--;
		}
		if (cnt >= K)
			break;
	}
	cout << i << "\n";


	return 0;
}

/*
 1 2 3 4 5 6 7
 2 4 6 8 101214
 3 6 9 12151821
 4 8 1216202428

100000
1000000000

1000
1000000

10000
100000000

*/