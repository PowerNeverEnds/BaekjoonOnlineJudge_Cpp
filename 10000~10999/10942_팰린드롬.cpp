/**
 *    BOJ 10942
 *    - 팰린드롬?
 *    author:  phcdream
 *    created: 오후 9:26 2020-12-02
**/

#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

struct MyStruct
{
	int l;
	int r;
};

void in(int& N, int*& arr, int**& visited)
{
	cin >> N;
	arr = new int[(ll)N + 1];
	fill(arr, arr + N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}


	visited = new int* [(ll)N + 1];
	fill(visited, visited + N + 1, nullptr);
	for (int i = 0; i < N + 1; i++)
	{
		visited[i] = new int[(ll)N + 1];
		fill(visited[i], visited[i] + N + 1, 0);
	}

}

void init(int& N, int*& arr, int**& visited)
{
	queue<MyStruct> q;								// 팰린드롬 S,E 저장(l,r)
	for (int i = 1; i <= N; i++)
	{
		visited[i][i] = 1;							//	길이가 1인 팰린드롬
		if (arr[i] == arr[i + 1] && i + 1 <= N)		//	길이가 2인 팰린드롬
		{
			visited[i][i + 1] = 1;
			q.push(MyStruct({ i,i + 1 }));
		}
		if (arr[i] == arr[i + 2] && i + 2 <= N)		//	길이가 3인 팰린드롬
		{
			visited[i][i + 2] = 1;
			q.push(MyStruct({ i,i + 2 }));
		}
	}

	MyStruct st;
	while (true)
	{
		if (q.empty())
			break;
		st = q.front();
		q.pop();
		MyStruct bnMS{ 1 <= st.l - 1, st.r + 1 <= N };
		MyStruct nMS{ st.l - 1,st.r + 1 };
		if (bnMS.l == 1 && bnMS.r == 1)
		{
			//	양쪽으로 +1 했을때도 팰린드롬
			if (arr[nMS.l] == arr[nMS.r])	// if문 추가.
			{
				visited[nMS.l][nMS.r] = 1;	// bnMS에서 nMS로 변경.
				q.push(MyStruct({ nMS.l,nMS.r }));	// bnMS에서 nMS로 변경.
			}
		}
	}
}

int solve(int N, int** visited, int S, int E)
{
	return visited[S][E];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	int** visited;
	in(N, arr, visited);
	init(N, arr, visited);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		bool re = solve(N, visited, S, E);
		cout << re << "\n";
	}

	return 0;
}

/*
7
1 2 1 3 1 2 1
4
1 3
2 5
3 3
5 7

8
1 2 2 1 3 2 3 1
27
1 4
2 3
4 8
5 7
6 6

1 2
1 3
1 5
1 6
1 7
1 8
2 4
2 5
2 7
2 8
3 4
3 5
3 6
3 7
3 8
4 5
4 6
4 7
5 6
5 8
6 7
6 8

4
1 2 2 3
2
2 3
1 4

4
1 2 2 3
2
2 3
1 4

6
3 1 2 2 1 3
2
2 5
1 6

*/