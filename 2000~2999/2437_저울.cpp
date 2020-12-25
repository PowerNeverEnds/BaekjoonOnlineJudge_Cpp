/**
 *    BOJ 2437
 *    - 저울
 *    author:  phcdream
 *    created: 오전 7:00 2020-12-07
**/

#include <iostream>
#include <queue>
#include <algorithm>

typedef long long ll;

#define MAX ((int)1e6+7)

using namespace std;

void in(int& N, int*& arr)
{
	cin >> N;
	arr = new int[(ll)N];
	fill(arr, arr + N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

//void bfs(int d, queue<int>& q, bool*& visited)
//{
//	int size = q.size();
//	int st;
//	if (visited[d] == false)	// 얘는 size계산에 안들어감.
//	{
//		visited[d] = true;
//		q.push(d);
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		st = q.front();
//		q.pop();
//		if (st + d < MAX && visited[st + d] == false)
//		{
//			visited[st + d] = true;
//			q.push(st + d);
//		}
//		q.push(st);		// 위치변경
//	}
//}

void print(bool*& visited)
{
	for (int i = 0; i < 10; i++)
		cout << visited[i] << " ";
	cout << "\n";
}

int solve(int N, int*& arr)
{
	bool* visited = new bool[MAX];
	fill(visited, visited + MAX, 0);
	//queue<int> q;
	//for (int i = 0; i < N; i++)
	//{
	//	bfs(arr[i], q, visited);
	//	//print(visited);
	//}

	//int i = 1;
	//for (i = 1; i < MAX; i++)
	//{
	//	if (visited[i] == false)
	//		break;
	//}

	//return i;

	sort(arr, arr + N, [](auto a, auto b) {
		return a < b;
		});

	int l = 0;
	for (int i = 0; i < N; i++)
	{
		if (l + 1 < arr[i])
			break;
		l += arr[i];
	}

	return l + 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int* arr;
	in(N, arr);

	int re = solve(N, arr);
	cout << re << "\n";

	return 0;
}