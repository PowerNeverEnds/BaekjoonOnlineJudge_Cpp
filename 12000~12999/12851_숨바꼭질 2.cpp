/*
https://www.acmicpc.net/source/23970116
*/

#include <iostream>
#include <queue>

typedef long long ll;

#define MAX 200001

using namespace std;

//int dx[3] = { -1,1,0 };

void bfs(int N, int* arr, ll* cntArr, int K)
{
	queue<int>q;
	arr[N] = 1;
	cntArr[N] = 1;
	q.push(N);
	bool find = false;
	int min = MAX;
	while (true)
	{
		//if (q.empty())
		//	break;
		N = q.front();
		q.pop();
		if (find && arr[N] != min)
			break;
		int dx[3] = { N-1,N+1,N*2 };
		for (int i = 0; i < 3; i++)
		{
			int nX;
			//if (dx[i] == 0)
			//	nX = N * 2;
			//else
			//	nX = N + dx[i];
			nX = dx[i];

			if (0 <= nX && nX < MAX)
			{
				if (arr[nX] == MAX || arr[nX] == arr[N] + 1)
				{
					if (arr[nX] == MAX)
					{
						q.push(nX);
					}
					arr[nX] = arr[N] + 1;
					cntArr[nX] += cntArr[N];
				}
				if (nX == K)
				{
					find = true;
					min = arr[N];
				}
			}
		}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	int* arr = new int[MAX];
	ll* cntArr = new ll[MAX];
	fill(arr, arr + MAX, MAX);
	fill(cntArr, cntArr + MAX, 0);
	bfs(N, arr, cntArr, K);

	//for (int i = 0; i <= N + K; i++)
	//{
	//	cout << arr[i] << " ";
	//}cout << "\n";
	//for (int i = 0; i <= N + K; i++)
	//{
	//	cout << cntArr[i] << " ";
	//}cout << "\n";

	cout << arr[K] - 1 << "\n";
	cout << cntArr[K] << "\n";

	return 0;
}

/*
5 17

5 4 8 16 17
5 10 9 18 17


1 1
0
1

0 1
1
1

1 0
1
1

4 6
2
2

0 100000

1 4
1 2 4
1 2 4

*/